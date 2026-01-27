package palisade.groundzero;

import javafx.scene.layout.Region;

public class UITheme {

    public static void apply(Region root) {
        root.setStyle(
            "-fx-background-color: #f1f1f1;" +
            "-fx-font-family: 'System';" +
            "-fx-text-fill: #111;"
        );
    }

    public static String buttonStyle() {
        return "-fx-background-color: #222;" +
               "-fx-text-fill: #eee;" +
               "-fx-background-radius: 4;";
    }
}