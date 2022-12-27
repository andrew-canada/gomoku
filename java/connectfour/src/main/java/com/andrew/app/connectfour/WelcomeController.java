package com.andrew.app.connectfour;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;

public class WelcomeController {
	private MatchController mc = MatchController.getInstance();

	@FXML
	private TextField name;

	public void confirm() throws IOException {
		String n = name.getText();
		Player p1 = new Player();
		p1.setName(n);
		p1.setPiece("-fx-background-color: black;");
		mc.setP1(p1);

		Player p2 = new Player();
		p2.setName("bob");
		p2.setPiece("-fx-background-color: red;");
		p2.setMoved(true);
		mc.setP2(p2);
		App.setRoot("secondary");
	}
}
