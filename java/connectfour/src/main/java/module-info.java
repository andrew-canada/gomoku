module com.andrew.app.connectfour {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.andrew.app.connectfour to javafx.fxml;
    exports com.andrew.app.connectfour;
}
