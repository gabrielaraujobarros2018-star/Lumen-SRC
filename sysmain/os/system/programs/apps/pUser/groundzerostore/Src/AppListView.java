package palisade.groundzero;

import javafx.scene.control.Button;
import javafx.scene.layout.VBox;

public class AppListView {

    private final VBox view;

    public AppListView() {
        view = new VBox(8);
        loadApps();
    }

    private void loadApps() {
        for (AppEntry app : AppScanner.scan()) {
            Button btn = new Button(app.getName());
            btn.setStyle(UITheme.buttonStyle());
            btn.setMaxWidth(Double.MAX_VALUE);
            btn.setOnAction(e -> AppLauncher.launchApp(app));
            view.getChildren().add(btn);
        }
    }

    public VBox getView() {
        return view;
    }
}