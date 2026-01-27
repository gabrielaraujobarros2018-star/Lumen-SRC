package palisade.groundzero;

import javafx.application.Application;
import javafx.stage.Stage;

public class GroundzeroStore extends Application {

    @Override
    public void start(Stage primaryStage) {
        Permissions.assertFullAccess();
        StoreWindow window = new StoreWindow(primaryStage);
        window.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

}