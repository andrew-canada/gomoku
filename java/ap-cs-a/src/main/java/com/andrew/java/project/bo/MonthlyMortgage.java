package com.andrew.java.project.bo;

public class MonthlyMortgage extends Mortgage {

	public MonthlyMortgage(double pricipal, double interestRate, int numberOfPayments) {
		setPricipal(pricipal);
		setInterestRate(interestRate);
		setNumberOfPayments(numberOfPayments);
	}

	@Override
	public double calculatePayment() {
		return getPricipal() * getInterestRate() * Math.pow((1 + getInterestRate()), getNumberOfPayments())
				/ (Math.pow((1 + getInterestRate()), getNumberOfPayments()) - 1);
	}
}
