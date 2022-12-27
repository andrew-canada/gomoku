package com.andrew.java.io;

import java.util.Scanner;

public class ReadingInput {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Your name: ");
		String name = scanner.nextLine();
		System.out.println("Hello " + name.trim());

	}

}
