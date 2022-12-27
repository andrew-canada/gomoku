package com.andrew.collections.stream;

import java.util.ArrayList;
import java.util.List;

import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class ReduceVsCollect {

	public static void main(String[] args) {

		List<Product> productList = ExampleData.getProducts();

		//@formatter:off
		List<String> reducedProdNames = productList.stream().reduce(
				new ArrayList<String>(), 
				(firstList, product) -> {
					ArrayList<String> secondList = new ArrayList<>(firstList);
					secondList.add(product.getName());
					return secondList;
				}, 
				(firstList, secondList) -> {
					ArrayList<String> combinedList = new ArrayList<>(firstList);
					combinedList.addAll(secondList);
					return combinedList;
				});
		reducedProdNames.forEach(System.out::println);
		
		List<String> collectedProdNames = productList.stream().collect(
				ArrayList::new, 
				(itemList, product) -> itemList.add(product.getName()), 
				ArrayList::addAll);
		collectedProdNames.forEach(System.out::println);
	}

}
