package com.andrew.shopping.bo;

public class CreditCard {

	private final int number;
	private double balance;

	public CreditCard(int number) {
		this.number = number;
	}

	public double getBalance() {
		return balance;
	}

	public void setBalance(double balance) {
		this.balance = balance;
	}

	@Override
	public String toString() {
		return "CreditCard [number=" + number + ", balance=" + balance + "]";
	}
}
