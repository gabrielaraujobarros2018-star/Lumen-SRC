use std::fs;
use std::path::Path;

fn main() {
    let app_name = "Aura Words";
    let target_img =
        "/palisade/os/framework/framework.Apps/\
programIMPORTS.Custom/adminApps/AuraWords.img";

    let shortcut_path =
        "/palisade/os/framework/framework.Apps/\
programIMPORTS.Custom/class.cpuGames/AuraWords";

    if !Path::new(target_img).exists() {
        eprintln!("AuraWords.img not found");
        return;
    }

    if !Path::new(shortcut_path).exists() {
        fs::create_dir_all(shortcut_path).unwrap();
    }

    let metadata = format!(
        "name={}\ntype=cpu-game\nbinary={}\ntrusted=true\n",
        app_name,
        target_img
    );

    let descriptor = format!("{}/app.link", shortcut_path);
    fs::write(descriptor, metadata).unwrap();

    println!("Aura Words shortcut registered");
}