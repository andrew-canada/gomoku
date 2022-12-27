package com.andrew.collections.stream;

import java.util.DoubleSummaryStatistics;
import java.util.List;
import java.util.stream.DoubleStream;

import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class SpecializedStreamExample {

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		//@formatter:off
		DoubleStream prodPrices = productList.stream()
				.mapToDouble(p -> p.getPrice().doubleValue());
		// prodPrices.forEach(System.out::println);
		
		double totalPrice = prodPrices.sum();
		System.out.println(totalPrice);
		
		DoubleSummaryStatistics prodStats = productList.stream()
				.mapToDouble(p -> p.getPrice().doubleValue())
				.summaryStatistics();
		
		System.out.println(prodStats.getCount());
		System.out.println(prodStats.getMax());
		System.out.println(prodStats.getSum());
		System.out.println(prodStats.getAverage());

	}

}
