package com.andrew.java.loops;

import java.util.Scanner;

public class WhileLoops {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String input = "";
		while (!input.equalsIgnoreCase("quit")) {
			System.out.print("Input: ");
			input = scanner.next();
			System.out.println(input);
		} // DoWhileLoops

		do {
			System.out.print("Input: ");
			input = scanner.next();
			System.out.println(input);
		} while (!input.equalsIgnoreCase("quit"));

		boolean isContinue = false;

		while (isContinue == true) {
			System.out.println("in isContinue while loop. isContinue is " + isContinue);
			isContinue = false;
		}
		String badString = "a";
		int i = 0;
		do {
			i = i + 1;
			System.out.println("in isContinue do...while loop. isContinue is " + isContinue);
			badString = badString + badString;

			System.out.println(badString);
			isContinue = true;
		} while (i < 10);

		System.out.println(badString);

		int number = 4;

		do {
			System.out.println("Number is greater than 5");
		} while (number > 5);
		System.out.println("Less than 5");

		while (number > 5) {
			System.out.println("Greater than 5");
		}
	}

}
