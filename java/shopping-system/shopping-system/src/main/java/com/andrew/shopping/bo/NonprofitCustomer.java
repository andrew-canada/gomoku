package com.andrew.shopping.bo;

public class NonprofitCustomer extends Customer {

	public NonprofitCustomer(String name, CreditCard creditCard) {
		super(name, creditCard);
	}

	public NonprofitCustomer(String name) {
		super(name);
	}

	@Override
	public int calculateDiscount() {
		return 10;
	}

}
