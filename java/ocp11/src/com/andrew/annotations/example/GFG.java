package com.andrew.annotations.example;

//Java code for Stream flatMap
//(Function mapper) to get a stream by
//replacing the stream with a mapped
//stream by applying the provided mapping function.
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class GFG {

	// Driver code
	public static void main(String[] args) {

		// Creating a List of Strings
		List<String> list = Arrays.asList("5.6", "7.4", "4", "1", "2.3");

		// Using Stream flatMap(Function mapper)
		list.stream().flatMap(num -> Stream.of(num)).forEach(System.out::println);
		list.stream().map(num -> num).forEach(System.out::println);

	}
}
