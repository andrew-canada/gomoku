package com.andrew.exercises.lambdas;

import java.util.List;

import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class ProductSorter {

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		productList.sort((p1, p2) -> p1.getName().compareTo(p2.getName()));

		productList.forEach(System.out::println);

	}

}
