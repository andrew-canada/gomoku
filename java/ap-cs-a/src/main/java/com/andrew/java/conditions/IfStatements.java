package com.andrew.java.conditions;

import java.util.Scanner;

public class IfStatements {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Temperature: ");
		int temperature = scanner.nextInt();

		if (temperature > 30) {
			System.out.println("It's a hot day \nDrink plenty of water");
		} else if (temperature >= 20 && temperature <= 30) {
			System.out.println("It's a nice day");
		} else {
			System.out.println("It's cold");
		}

		System.out.print("Degrees: ");
		int degrees = scanner.nextInt();
		scanner.close();
		String weatherCategory = degrees > 35 ? "Hot" : "Warm";
		System.out.println(weatherCategory);
	}

}
