package com.andrew.app.connectfour;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.shape.Circle;

public class PrimaryController {

	private MatchController mc = MatchController.getInstance();

	@FXML
	private Circle myCircle;

	@FXML
	private TextField name;

	private double x;
	private double y;

	public void switchToSecondary() throws IOException {
		String n = name.getText();
		Player p1 = new Player();
		p1.setName(n);
		mc.setP1(p1);
		App.setRoot("secondary");
	}

	public void moveUp() {
		myCircle.setCenterY(y -= 10);

	}

	public void moveDown() {
		myCircle.setCenterY(y += 10);

	}

	public void moveLeft() {
		myCircle.setCenterY(x -= 10);

	}

	public void moveRight() {
		myCircle.setCenterY(x += 10);

	}

}
