package palisade.groundzero;

public class AppEntry {

    private final String name;
    private final String path;

    public AppEntry(String name, String path) {
        this.name = name;
        this.path = path;
    }

    public String getName() {
        return name;
    }

    public String getPath() {
        return path;
    }
}