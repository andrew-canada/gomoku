package com.andrew.exercises.lambdas;

import java.util.ArrayList;
import java.util.List;

import com.andrew.exercises.model.Category;
import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;
import com.andrew.exercises.model.ProductFilter;

public class ProductSearcher {

	public static boolean isCleaningProduct(Product p) {
		return p.getCategory() == Category.CLEANING;
	}

	public static List<Product> findProductsByCategory(List<Product> productList, ProductFilter<Product> pf) {

		List<Product> products = new ArrayList<>();
		for (Product product : productList) {
			if (pf.accept(product)) {
				products.add(product);
			}
		}
		return products;

	}

	public static List<Product> findProductsByCategoryStream(List<Product> productList) {

		return productList.stream().filter(ProductSearcher::isCleaningProduct).toList();

	}

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		ProductFilter<Product> pf = product -> product.getCategory() == Category.CLEANING;

		List<Product> cleaningProductList = findProductsByCategory(productList, pf);

		cleaningProductList.forEach(System.out::println);

		System.out.println("--stream--");

		List<Product> cleaningProductList2 = findProductsByCategoryStream(productList);

		cleaningProductList2.forEach(System.out::println);

	}

}
