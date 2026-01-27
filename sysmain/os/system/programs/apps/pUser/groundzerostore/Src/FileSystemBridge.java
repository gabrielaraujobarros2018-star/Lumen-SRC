package palisade.groundzero;

import java.io.File;

public class FileSystemBridge {

    public static boolean exists(String path) {
        return new File(path).exists();
    }

    public static String[] list(String path) {
        File dir = new File(path);
        return dir.exists() ? dir.list() : new String[0];
    }
}