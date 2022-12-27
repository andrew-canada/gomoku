package com.andrew.function;

import java.util.List;
import java.util.Optional;
import java.util.function.Predicate;

import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

//@formatter:off
/*
 * use std fi with product list
 * 		1. find product based on some criteria
 * 			- input: products, predicate 
 * 			- output: Optional<product> (could return product or empty -> avoid return null)
 */

//@formatter:on
public class StdFiTest {

	public static Optional<Product> findProduct(List<Product> productList, Predicate<Product> pred) {
		for (Product p : productList) {
			if (pred.test(p)) {
				return Optional.of(p);
			}
		}
		return Optional.empty();
	}

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		String productName = "Plates";

		//@formatter:off
		findProduct(productList, p -> p.getName().equals(productName))
			.map(Product::getPrice)
			.ifPresentOrElse(
				productPrice -> System.out.printf(("%s costs $ %.3f "), productName, productPrice),
				() -> System.out.printf(("%s not found"), productName));
	}

}
