package palisade.groundzero;

import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

public class StoreWindow {

    private final Stage stage;

    public StoreWindow(Stage stage) {
        this.stage = stage;
    }

    public void show() {
        BorderPane root = new BorderPane();
        UITheme.apply(root);

        AppListView listView = new AppListView();
        root.setCenter(listView.getView());

        Scene scene = new Scene(root, 640, 420);
        stage.setTitle("GroundzeroStore");
        stage.setScene(scene);
        stage.show();
    }
}