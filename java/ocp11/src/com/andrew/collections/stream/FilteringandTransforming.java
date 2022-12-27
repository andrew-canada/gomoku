package com.andrew.collections.stream;

import java.util.List;
import java.util.regex.Pattern;
import java.util.stream.Stream;

import com.andrew.exercises.model.Category;
import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class FilteringandTransforming {

	public static void main(String[] args) {

		List<Product> productList = ExampleData.getProducts();

		//@formatter:off
		productList.stream()
			.filter(p -> p.getCategory() == Category.CLEANING)
			.forEach(System.out::println);
		
		productList.stream()
			.map(p -> String.format("Price of %s is $%.2f", p.getName(), p.getPrice()))
			.forEach(System.out::println);
		
		Pattern spaces = Pattern.compile("\\s+");
/*		productList.stream()
			.map(p -> spaces.splitAsStream(p.getName()))
			.forEach(System.out::println);*/
		
		productList.stream()
			.flatMap(p -> spaces.splitAsStream(p.getName()))
			.forEach(System.out::println);
		
		Stream<String> stringStream = productList.stream()
			.flatMap(p -> spaces.splitAsStream(p.getName()));
		
		stringStream.forEach(System.out::println);
			
	}

}
