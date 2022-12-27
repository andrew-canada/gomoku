package com.andrew.java.project;

import java.util.Scanner;

public class MortgageCalculator {

	public static void main(String[] args) {
		Scanner p = new Scanner(System.in);
		System.out.print("Principal: ");
		String Principal = p.nextLine();
		int pr = Integer.parseInt(Principal);
		// System.out.println(pr);

		Scanner r = new Scanner(System.in);
		System.out.print("Monthly Interest Rate: ");
		String Rate = r.nextLine();
		double ra = Integer.parseInt(Rate);
		// String Rat = NumberFormat.getPercentInstance().format(ra);
		// int rate = Integer.parseInt(Rat);
		double rate = ra / 100;
		// System.out.println(rate);

		Scanner y = new Scanner(System.in);
		System.out.print("Period (Months): ");
		String Period = y.nextLine();
		int pe = Integer.parseInt(Period);
		// System.out.println(pe);

		// System.out.println(pr + rate + pe);

		System.out.println(pr * rate * Math.pow((1 + rate), pe) / Math.pow((1 + rate), pe) - 1);
		// System.out.println(pr * rate * Math.pow((1 + rate), pe));

		// Improvements:
		// Make meaningful variable names. No magic words.
		// Do not have "magic numbers" unexplained numbers. Use constants.
		// Format values (NumberFormat.getCurrencyInstance())
	}

}
