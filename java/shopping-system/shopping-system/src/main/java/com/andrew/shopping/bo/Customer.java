package com.andrew.shopping.bo;

public abstract class Customer {

	private final String name;
	private CreditCard creditCard;
	private ShoppingCart shoppingCart;

	public Customer(String name, CreditCard creditCard) {
		this.name = name;
		this.creditCard = creditCard;
	}

	public Customer(String name) {
		this.name = name;
	}

	public ShoppingCart getShoppingCart() {
		return shoppingCart;
	}

	public void setShoppingCart(ShoppingCart shoppingCart) {
		this.shoppingCart = shoppingCart;
	}

	public void addProduct(Product product) {
		this.shoppingCart.getProductList().add(product);
	}

	public abstract int calculateDiscount();

	@Override
	public String toString() {
		return "Customer [name=" + name + ", creditCard=" + creditCard + ", shoppingCart=" + shoppingCart + "]";
	}

}
