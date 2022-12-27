package com.andrew.app.connectfour;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;

public class SecondaryController {

	private MatchController mc = MatchController.getInstance();

	@FXML
	GridPane board;

	@FXML
	private void switchToPrimary() throws IOException {
		App.setRoot("primary");
	}

	public void move(javafx.scene.input.MouseEvent event) {
		Pane source = (Pane) event.getSource();
		source.setCenterShape(true);
		Image image = new Image("a.png");
		ImageView iw = new ImageView(image);
		source.getChildren().add(iw);
		Player p = mc.whoNext();
		Text t = new Text(p.getName());
		source.getChildren().add(t);
		source.setStyle(p.getPiece());

	}
}