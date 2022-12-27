package com.andrew.collections.stream;

import java.math.BigDecimal;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import com.andrew.exercises.model.Category;
import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class CollectorsTest {

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		Map<Category, BigDecimal> categoryTotals = productList.stream()
				.collect(Collectors.toMap(Product::getCategory, Product::getPrice, BigDecimal::add));

		System.out.println(categoryTotals);
	}

}
