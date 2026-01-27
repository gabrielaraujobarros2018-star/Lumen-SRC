use std::fs;
use std::path::Path;

#[derive(Debug, Clone, Copy)]
pub enum AppType {
    Admin,
    CpuGame,
    User,
    Service,
    Tool,
}

#[derive(Debug)]
pub struct AppEntry {
    pub name: String,
    pub app_type: AppType,
    pub binary: String,
    pub trusted: bool,
}

pub struct AppManager {
    pub apps: Vec<AppEntry>,
}

impl AppManager {
    pub fn new() -> Self {
        AppManager { apps: Vec::new() }
    }

    pub fn scan(&mut self) {
        self.scan_dir(
            "/palisade/os/framework/framework.Apps/\
programIMPORTS.Custom/adminApps",
            AppType::Admin,
        );
        self.scan_dir(
            "/palisade/os/framework/framework.Apps/\
programIMPORTS.Custom/class.cpuGames",
            AppType::CpuGame,
        );
        self.scan_dir(
            "/palisade/os/framework/framework.Apps/userApps",
            AppType::User,
        );
    }

    fn scan_dir(&mut self, path: &str, app_type: AppType) {
        if !Path::new(path).exists() {
            return;
        }

        let entries = fs::read_dir(path).unwrap();
        for entry in entries {
            if let Ok(entry) = entry {
                let p = entry.path();
                if p.is_dir() {
                    self.load_app(p, &app_type);
                }
            }
        }
    }

    fn load_app(&mut self, dir: std::path::PathBuf, app_type: &AppType) {
        let link = dir.join("app.link");
        if !link.exists() {
            return;
        }

        let content = fs::read_to_string(link).unwrap();
        let mut name = String::new();
        let mut binary = String::new();
        let mut trusted = false;

        for line in content.lines() {
            if line.starts_with("name=") {
                name = line[5..].to_string();
            } else if line.starts_with("binary=") {
                binary = line[7..].to_string();
            } else if line.starts_with("trusted=") {
                trusted = &line[8..] == "true";
            }
        }

        self.apps.push(AppEntry {
            name,
            app_type: app_type.clone(),
            binary,
            trusted,
        });
    }

    pub fn list(&self) {
        for app in &self.apps {
            println!("{:?} :: {}", app.app_type, app.name);
        }
    }

    pub fn launch(&self, name: &str) {
        for app in &self.apps {
            if app.name == name {
                if app.trusted {
                    std::process::Command::new(&app.binary)
                        .spawn()
                        .unwrap();
                }
            }
        }
    }
}

fn main() {
    let mut manager = AppManager::new();
    manager.scan();
    manager.list();
}
