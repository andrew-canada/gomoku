package com.andrew.app.connectfour;

public class MatchController {

	private Player p1;
	private Player p2;
	private static MatchController matchController;

	private MatchController() {
	}

	public static MatchController getInstance() {
		if (matchController == null) {
			matchController = new MatchController();
		}
		return matchController;
	}

	public Player whoNext() {
		if (p1.isMoved()) {
			p1.setMoved(false);
			p2.setMoved(true);
			return p2;
		} else {
			p1.setMoved(true);
			p2.setMoved(false);
			return p1;
		}

	}

	public Player getP1() {
		return p1;
	}

	public void setP1(Player p1) {
		this.p1 = p1;
	}

	public Player getP2() {
		return p2;
	}

	public void setP2(Player p2) {
		this.p2 = p2;
	}
}
