package com.andrew.java.project.bo;

public class Mortgage {

	private double pricipal;
	private double interestRate;
	private int numberOfPayments;

	public Mortgage() {

	}

	public Mortgage(double pricipal, double interestRate, int numberOfPayments) {
		super();
		this.pricipal = pricipal;
		this.interestRate = interestRate;
		this.numberOfPayments = numberOfPayments;
	}

	public int getNumberOfPayments() {
		return numberOfPayments;
	}

	public void setNumberOfPayments(int numberOfPayments) {
		this.numberOfPayments = numberOfPayments;
	}

	public double getPricipal() {
		return pricipal;
	}

	public void setPricipal(double pricipal) {
		this.pricipal = pricipal;
	}

	public double getInterestRate() {
		return interestRate;
	}

	public void setInterestRate(double interestRate) {
		this.interestRate = interestRate;
	}

	public double calculatePayment() {
		return 1.0;
	}
}
