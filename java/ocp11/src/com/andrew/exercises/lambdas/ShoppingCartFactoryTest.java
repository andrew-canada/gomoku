package com.andrew.exercises.lambdas;

import java.util.List;

import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;
import com.andrew.exercises.model.ShoppingCart;
import com.andrew.exercises.model.ShoppingCartFacatory;

public class ShoppingCartFactoryTest {

	public static ShoppingCartFacatory getShoppingCartFacatory() {

		return ShoppingCart::new;
	}

	public static void main(String[] args) {

		List<Product> productList = ExampleData.getProducts();

		ShoppingCart sc = getShoppingCartFacatory().newShoppingCart();

		sc.add(productList);

		System.out.println(sc.getTotalAmount());

	}

}
