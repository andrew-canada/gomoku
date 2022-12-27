package com.andrew.collections.stream;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.stream.IntStream;
import java.util.stream.Stream;

import com.andrew.exercises.model.ExampleData;
import com.andrew.exercises.model.Product;

public class CreateStreamExample {

	public static void main(String[] args) {

		List<Product> productList = ExampleData.getProducts();
		Stream<Product> ps = productList.stream();

		String[] array = new String[] { "one", "two", "three" };
		Stream<String> stringStream1 = Arrays.stream(array);

		Stream<String> stringStream2 = Stream.of(array);

		Stream<String> stringStream3 = Stream.ofNullable("single element");
		Stream<String> nullStream = Stream.ofNullable(null);
		nullStream.forEach(System.out::println);

		Stream<?> emptyStream = Stream.empty();

		IntStream is = new Random().ints();
		// is.forEach(System.out::println);

		try (BufferedReader readFile = new BufferedReader(new FileReader("testData.txt"))) {
			readFile.lines().forEach(System.out::println);
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}

}
