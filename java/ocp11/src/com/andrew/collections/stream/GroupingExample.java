package com.andrew.collections.stream;

import java.math.BigDecimal;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import com.andrew.exercises.model.Category;
import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class GroupingExample {

	public static void main(String[] args) {

		List<Product> productList = ExampleData.getProducts();

		Map<Category, List<Product>> prodByCategory = productList.stream()
				.collect(Collectors.groupingBy(Product::getCategory));
		System.out.println(prodByCategory);

		//@formatter:off
		Map<Category, List<String>> prodNamesByCategory = productList.stream()
				.collect(Collectors.groupingBy(
						Product::getCategory,
						Collectors.mapping(Product::getName, Collectors.toList()))); 
		System.out.println(prodNamesByCategory);

		Map<Category, BigDecimal> totalByCategory = productList.stream()
				.collect(Collectors.groupingBy(
						Product::getCategory,
						Collectors.mapping(Product::getPrice, Collectors.reducing(BigDecimal.ZERO, BigDecimal::add))));
		System.out.println(totalByCategory);
	}

}
