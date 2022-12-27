package com.andrew.java.arrays;

import java.util.Arrays;

public class SingleDimensionArrays {

	public static void main(String[] args) {

		// method 1
		// [6] means 6 numbers, not index 6
		int[] ages = new int[6];
		ages[0] = 1;
		ages[3] = 4;

		// prints the memory address of the object
		System.out.println(ages);

		String[] names = { "andrew", "bob" };
		String[] ranks = new String[2];
		ranks[0] = "first";
		ranks[1] = "second";
		System.out.println(Arrays.toString(names));
		// prints the values in the array
		// default value is 0
		System.out.println(Arrays.toString(ages));
		// the default toString of array doesn't work
		System.out.println(ages.toString());

		// method 2
		int[] weights = { 95, 83, 42, 74, 11 };
		System.out.println("before sort: " + Arrays.toString(weights));
		System.out.println(weights.length);
		Arrays.sort(weights);
		System.out.println("after sort: " + Arrays.toString(weights));

	}

}
