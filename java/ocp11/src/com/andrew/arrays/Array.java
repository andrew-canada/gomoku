package com.andrew.arrays;

import java.util.Arrays;

public class Array {

	// variable arguments; can give value to args
	public static void main(String[] args) {
		// takes 3 memory addresses without initializing - default value 0
		int[] intArray1 = new int[3];
		System.out.println(intArray1[0]);
		// initializes 3 memory addresses
		int[] intArray2 = { 1, 2, 3 };
		System.out.println(intArray2[0]);

		for (int i = 0; i < intArray2.length; i++) {
			System.out.println(intArray2[i]);
		}
		for (int element : intArray2) {
			System.out.println(element);
		}

		String[] stringArray1 = new String[3];
		stringArray1[1] = "piano";
		stringArray1[2] = "abacus";
		// doesn't reference anything -> null
		System.out.println(stringArray1[0]);

		// object id
		System.out.println(stringArray1);
		// values
		System.out.println(Arrays.toString(stringArray1));
		// can't sort because stringArray1[0] is null
		// Arrays.sort(stringArray1);
		stringArray1[0] = "computer";
		Arrays.sort(stringArray1);
		System.out.println(Arrays.toString(stringArray1));

		int[] numbers = { 1, 7, 3, 8, 4, 2, -1 };
		// -2 -> unpredictable result because numbers isn't sorted
		System.out.println(Arrays.binarySearch(numbers, 2));
		// -8 -> negative number because 90 isn't in the array
		System.out.println(Arrays.binarySearch(numbers, 90));
		Arrays.sort(numbers);
		// 2 -> correct because numbers is sorted
		System.out.println(Arrays.binarySearch(numbers, 2));

		int[] integers1 = { 1, 2, 3, 4, 5 };
		int[] integers2 = { 1, 2, 3, 4, 5 };
		int[] integers3 = { 1, 2, 3, 4, 6, 7 };

		// compares memory address
		System.out.println(integers1.equals(integers2));
		// compares if elements are in same order
		System.out.println(Arrays.equals(integers1, integers2));
		// compares smaller, equals, bigger
		System.out.println(Arrays.compare(integers2, integers3));
		// finds first point of difference; if equal, return -1
		System.out.println(Arrays.mismatch(integers2, integers3));

		// multi-dimensional array needs self-defined tostring
	}

}
