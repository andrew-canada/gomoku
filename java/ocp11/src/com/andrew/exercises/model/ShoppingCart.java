package com.andrew.exercises.model;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

public class ShoppingCart {

	private final List<Product> products = new ArrayList<>();

	public void add(Product product) {
		this.products.add(product);
	}

	public void add(List<Product> productList) {
		this.products.addAll(productList);
	}

	public BigDecimal getTotalAmount() {
		BigDecimal total = BigDecimal.ZERO;

		// TODO: This solution does not work. Can you explain why?
		// products.forEach(product -> total.add(product.getPrice()));
		return products.stream().map(Product::getPrice).reduce(BigDecimal.ZERO, BigDecimal::add);
	}

}
