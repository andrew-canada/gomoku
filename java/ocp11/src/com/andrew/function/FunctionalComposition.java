package com.andrew.function;

import java.math.BigDecimal;
import java.util.List;
import java.util.Optional;
import java.util.function.Function;
import java.util.function.Predicate;

import com.andrew.exercises.model.Category;
import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

/*
 * combines functions into new function
 * find first product that is food and is cheap
 */

public class FunctionalComposition {

	public static Optional<Product> findProduct(List<Product> productList, Predicate<Product> pred) {
		for (Product p : productList) {
			if (pred.test(p)) {
				return Optional.of(p);
			}
		}
		return Optional.empty();
	}

	public static void main(String[] args) {
		List<Product> productList = ExampleData.getProducts();

		String productName = "Plates";

		Function<Product, BigDecimal> productToPrice = Product::getPrice;
		Function<BigDecimal, String> priceToMessage = price -> String.format("Price for %s is $ %.2f", productName,
				price);

		Function<Product, String> productToMessage = productToPrice.andThen(priceToMessage);

		//@formatter:off
		findProduct(productList, p -> p.getName().equals(productName))
			.map(productToMessage)
			.ifPresentOrElse(
					System.out::println,
					() -> System.out.printf(("%s not found"), productName));
		
		//@formatter:on
		// find cheap food item
		Predicate<Product> isFood = p -> p.getCategory() == Category.FOOD;
		Predicate<Product> isCheap = p -> p.getPrice().doubleValue() < 1;

		Predicate<Product> isCheapFood = isFood.and(isCheap);

		Function<BigDecimal, String> cheapFoodPriceToMsg = price -> String.format("Cheapest food is $%.2f!", price);
		Function<Product, String> cheapFoodProdToMsg = productToPrice.andThen(cheapFoodPriceToMsg);

		//@formatter:off
		findProduct(productList, isCheapFood)
			.map(cheapFoodProdToMsg)
			.ifPresentOrElse(
					System.out::println,
					() -> System.out.printf(("no cheap food")));

	}

}
