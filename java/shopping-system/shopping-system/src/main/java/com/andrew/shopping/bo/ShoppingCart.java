package com.andrew.shopping.bo;

import java.util.ArrayList;
import java.util.List;

public class ShoppingCart {

	private List<Product> productList = new ArrayList<>();

	public List<Product> getProductList() {
		return productList;
	}

	public void setProductList(List<Product> productList) {
		this.productList = productList;
	}

	public double getTotalCost() {
		return productList.stream().mapToDouble(Product::getPrice).sum();
	}

	@Override
	public String toString() {
		return "ShoppingCart [productList=" + productList + "]";
	}
}
