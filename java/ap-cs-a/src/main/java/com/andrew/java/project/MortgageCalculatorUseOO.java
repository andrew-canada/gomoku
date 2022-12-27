package com.andrew.java.project;

import java.util.Scanner;

import com.andrew.java.project.bo.AnnualMortgage;
import com.andrew.java.project.bo.MonthlyMortgage;
import com.andrew.java.project.bo.Mortgage;

public class MortgageCalculatorUseOO {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Principal: ");
		String Principal = scanner.nextLine();
		double pr = 1.0;
		try {
			pr = Integer.parseInt(Principal);
		} catch (Exception e) {
			System.out.println(e);
		}
		System.out.print("Monthly Interest Rate: ");
		String Rate = scanner.nextLine();
		double ra = Integer.parseInt(Rate);
		System.out.print("Period (Months): ");
		String Period = scanner.nextLine();
		int pe = Integer.parseInt(Period);

		scanner.close();

		Mortgage m1 = new Mortgage(pr, ra, pe);
		System.out.println(m1.calculatePayment());

		Mortgage m2 = new MonthlyMortgage(pr, ra, pe);
		System.out.println(m2.calculatePayment());

		Mortgage m3 = new AnnualMortgage(pr, ra, pe);
		System.out.println(m3.calculatePayment());

	}

}
