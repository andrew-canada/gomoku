package com.andrew.java.project;

import java.text.NumberFormat;
import java.util.Scanner;

public class MortgageCalculatorWithErrorHandling {

	public static void main(String[] args) {
		final int monthsInYear = 12;
		final int percent = 100;
		Scanner scanner = new Scanner(System.in);
		double principal = 0;
		while (true) {
			System.out.print("Principal ($1K - $1M): ");
			principal = scanner.nextDouble();
			if (principal >= 1000 && principal <= 1_000_000) {
				break;
			}
			System.out.println("Enter a number between 1,000 and 1,000,000.");
		}
		double rate = 0;
		while (true) {
			System.out.print("Annual Interest Rate: ");
			rate = scanner.nextDouble();
			if (rate > 0 && rate <= 30) {
				break;
			}
			rate = rate / percent;
			System.out.println("Enter a value greater than 0 and less than or equal to 30.");
		}
		double period = 0;
		while (true) {
			System.out.print("Period (Years): ");
			period = scanner.nextDouble();
			if (period >= 1 && period <= 30) {
				break;
			}
			period = period * monthsInYear;
			System.out.println("Enter a value between 1 and 30.");
		}
		scanner.close();

		System.out.println("Mortgage: " + NumberFormat.getCurrencyInstance()
				.format(principal * rate * Math.pow((1 + rate), period) / Math.pow((1 + rate), period) - 1));

	}
}
// Improvements: Break things into chunks. 
