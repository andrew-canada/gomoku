package com.andrew.collections.stream;

import java.util.List;
import java.util.Optional;

import com.andrew.exercises.model.Category;
import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class SearchingStreams {

	public static void main(String[] args) {

		List<Product> productList = ExampleData.getProducts();

		//@formatter:off
		Optional<Product> firstCleaningProd = productList.stream()
				.filter(p -> p.getCategory()==Category.CLEANING)
				.findFirst();
		firstCleaningProd.ifPresent(System.out::println);
		
		Optional<Product> anyCleaningProd = productList.stream()
				.filter(p -> p.getCategory() == Category.CLEANING)
				.findAny();
		anyCleaningProd.ifPresent(System.out::println);
		
		boolean isCleaningFound = productList.stream()
				.anyMatch(p -> p.getCategory() == Category.CLEANING);
		System.out.println("is cleaning found? " + isCleaningFound);
		
		boolean areAllCheap = productList.stream()
				.allMatch(p -> p.getPrice().doubleValue() < 10);
		System.out.println("are all cheap? " + areAllCheap);
		
		boolean areAllExpensive = productList.stream()
				.noneMatch(p -> p.getPrice().doubleValue() < 1);
		System.out.println("are all expensive? " + areAllExpensive);
	}

}
