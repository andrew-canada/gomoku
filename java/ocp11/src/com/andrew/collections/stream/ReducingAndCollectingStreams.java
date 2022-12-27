package com.andrew.collections.stream;

import java.math.BigDecimal;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import com.andrew.exercises.model.Category;
import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class ReducingAndCollectingStreams {

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		//@formatter:off
		List<String> foodNames = productList.stream()
				.filter(p -> p.getCategory() == Category.FOOD)
				.map(Product::getName)
				.toList();
		foodNames.forEach(System.out::println);
		
		String productCategories = productList.stream()
				.map(Product::getCategory)
				.distinct()
				.map(Category::name)
				.collect(Collectors.joining(", "));
		System.out.println(productCategories);
		
		String pc = productList.stream()
				.map(Product::getCategory)
				.distinct()
				.map(Category::toString)
				.collect(Collectors.joining(", "));
		System.out.println(pc);
		
		// reduce
		
		Optional<BigDecimal> prodPriceSum = productList.stream()
				.map(Product::getPrice)
				.reduce(BigDecimal::add);
		prodPriceSum.ifPresentOrElse(
				total -> System.out.printf("total price is: $%.2f%n", total), 
				() -> System.out.println("no products"));

		
		BigDecimal twoParamTotal = productList.stream()
				.map(Product::getPrice)
				.reduce(BigDecimal.ZERO, BigDecimal::add);
		System.out.println(twoParamTotal);
		
		BigDecimal threeParamTotal = productList.stream()
				.reduce(BigDecimal.ZERO, (total, product) -> total.add(product.getPrice()), BigDecimal::add);
		System.out.println(threeParamTotal);
	}

}
