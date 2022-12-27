package com.andrew.shopping.bo;

public class BusinessCustomer extends Customer {

	public BusinessCustomer(String name, CreditCard creditCard) {
		super(name, creditCard);
	}

	@Override
	public int calculateDiscount() {
		return 15;
	}

}
