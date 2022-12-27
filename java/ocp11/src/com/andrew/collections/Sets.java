package com.andrew.collections;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Sets {

	public static void main(String[] args) {
		Set<String> unorderedNames = new HashSet<>();
		Set<String> orderedNames = new TreeSet<>();

		unorderedNames.add("steve");
		unorderedNames.add("bob");
		unorderedNames.add("john");

		orderedNames.add("steve");
		orderedNames.add("bob");
		orderedNames.add("john");

		// random order
		unorderedNames.forEach(System.out::println);
		System.out.println();
		// sorted order
		orderedNames.forEach(System.out::println);
		System.out.println();

		System.out.println(unorderedNames.add("jane"));
		// sets are unique -> no duplicates -> can't add again
		System.out.println(unorderedNames.add("jane"));

		System.out.println();
		unorderedNames.forEach(System.out::println);

		System.out.println(unorderedNames.isEmpty());
		System.out.println();

		unorderedNames.remove("jane");
		System.out.println(unorderedNames.isEmpty());
		unorderedNames.forEach(System.out::println);

	}

}
