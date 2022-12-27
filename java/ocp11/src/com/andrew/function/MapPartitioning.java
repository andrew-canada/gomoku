package com.andrew.function;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import com.andrew.exercises.model.Category;
import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

/*
 * partition list of products into map of lists based on category
 * computeIfAbsent
 */

public class MapPartitioning {

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		Map<Category, List<Product>> productMap = new HashMap<>();

		productMap = productList.stream().collect(Collectors.groupingByConcurrent(Product::getCategory));

		/*
		 * for (Product prod : productList) {
		 * 
		 * Category c = prod.getCategory();
		 * 
		 * productMap.computeIfAbsent(c, cc -> new ArrayList<Product>()).add(prod); }
		 */

		productMap.forEach((k, l) -> {
			System.out.println(k);
			l.forEach(System.out::println);
		});
	}

}
