package palisade.groundzero;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class AppScanner {

    private static final String USER_APPS_PATH =
        "/palisade/os/framework/framework.Apps.Import.GroundzeroStore/programIMPORTS.userimports";

    public static List<AppEntry> scan() {
        List<AppEntry> apps = new ArrayList<>();
        File root = new File(USER_APPS_PATH);

        if (!root.exists()) return apps;

        for (File file : root.listFiles()) {
            if (file.isFile()) {
                apps.add(new AppEntry(file.getName(), file.getAbsolutePath()));
            }
        }
        return apps;
    }
}