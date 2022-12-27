package com.andrew.java.loops;

import java.util.Scanner;

public class BreakAndContinue {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);
		String input = "";

		while (!input.equalsIgnoreCase("quit")) {
			System.out.print("Input: ");
			input = scanner.next();
			if (!input.equalsIgnoreCase("quit")) {
				System.out.println(input);
			}
		}

		while (!input.equalsIgnoreCase("quit")) {
			System.out.print("Input: ");
			input = scanner.next();
			if (input.equalsIgnoreCase("quit")) {
				break;
			}
			System.out.println(input);

		}

		while (!input.equalsIgnoreCase("quit")) {
			System.out.print("Input: ");
			input = scanner.next();
			if (input.equalsIgnoreCase("pass")) {
				continue;
			}
			if (input.equalsIgnoreCase("quit")) {
				break;
			}
			System.out.println(input);
		}
	}
}
