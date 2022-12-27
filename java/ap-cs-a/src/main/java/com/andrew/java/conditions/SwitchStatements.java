package com.andrew.java.conditions;

public class SwitchStatements {

	public static void main(String[] args) {
		String role = "admin";

		switch (role) {
		case "admin":
			System.out.println("Admin");
			break;

		case "moderator":
			System.out.println("Moderator");
			break;

		case "guest":
			System.out.println("Guest");
			break;

		default:
			System.out.println("Person");
		}

	}
}
