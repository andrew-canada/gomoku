package com.andrew.java.exercise;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class FizzBuzz {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("dividend: ");
		int dividend = scanner.nextInt();
		System.out.print("divisor: ");
		int divisor = scanner.nextInt();
		scanner.close();

		if (dividend % 5 == 0 && dividend % 3 == 0) {
			System.out.println("FizzBuzz");

		} else if (dividend % 5 == 0) {
			System.out.println("Fizz");

		} else if (dividend % 3 == 0) {
			System.out.println("Buzz");

		} else {
			System.out.println(dividend);
		}

		int remainder = dividend % 5;

		System.out.println("remainder of " + dividend + "%" + divisor + " is " + remainder);
		switch (remainder) {
		case 0:
			System.out.println("Good");
			break;
		default:
			System.out.println("no match");
		}

		String doesMatch = "true";

		switch (doesMatch) {
		case "true":
			System.out.println("it does match");
		default:
			System.out.println("no match");
		}

		Integer[] remainders = new Integer[] { dividend % 5, dividend % 3 };
		List<Integer> listOfRemainder = Arrays.asList(remainders);
		if (listOfRemainder.contains(0)) {
			System.out.println("FizzBuzz");
			System.out.println(listOfRemainder);

		} else {
			System.out.println("bad");
			listOfRemainder.forEach(System.out::print);
		}

	}
}