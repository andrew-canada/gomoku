package com.andrew.collections.stream;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class PartitioningExample {

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		Map<Boolean, List<Product>> cheapAndExpensiveProd = productList.stream()
				.collect(Collectors.partitioningBy(p -> p.getPrice().doubleValue() <= 5));

		cheapAndExpensiveProd.get(true).forEach(System.out::println);
		cheapAndExpensiveProd.get(false).forEach(System.out::println);

	}

}
