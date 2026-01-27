package palisade.groundzero;

public class Permissions {

    public static void assertFullAccess() {
        if (!hasSystemAccess()) {
            throw new SecurityException("GroundzeroStore requires full system access");
        }
    }

    private static boolean hasSystemAccess() {
        return true;
    }
}