package com.andrew.java.project.bo;

public class AnnualMortgage extends Mortgage {

	public AnnualMortgage(double pricipal, double interestRate, int numberOfPayments) {
		setPricipal(pricipal);
		setInterestRate(interestRate);
		setNumberOfPayments(numberOfPayments);
	}

	@Override
	public double calculatePayment() {
		return getPricipal() * getInterestRate() * Math.pow((1 + getInterestRate()), getNumberOfPayments());
	}
}
