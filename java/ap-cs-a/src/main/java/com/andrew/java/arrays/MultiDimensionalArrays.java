package com.andrew.java.arrays;

import java.util.Arrays;

public class MultiDimensionalArrays {

	public static void main(String[] args) {
		int[][] numbers = new int[3][4];
		numbers[0][0] = 8;
		numbers[1][2] = 11;
		System.out.println(Arrays.deepToString(numbers));

		String[][] names = { { "joe", "", "andrew" }, { "", "", "bob" } };
		System.out.println(Arrays.deepToString(names));
		System.out.println(names[1][2]);
		System.out.println(Arrays.toString(names[1]));

	}

}
