package palisade.groundzero;

import java.io.File;

public class AppLauncher {

    public static void launchApp(AppEntry app) {
        try {
            File executable = new File(app.getPath());
            if (!executable.exists()) return;

            ProcessBuilder builder = new ProcessBuilder(executable.getAbsolutePath());
            builder.inheritIO();
            builder.start();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}