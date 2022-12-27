package com.andrew.datatypes.lists;
import java.util.Arrays;

import com.andrew.shopping.bo.NonprofitCustomer;

public class ArrayMain {

	public static void main(String[] args) {

		NonprofitCustomer c1 = new NonprofitCustomer("joe");
		NonprofitCustomer c2 = new NonprofitCustomer("bob");

		NonprofitCustomer[] customerArray = { c1, c2 };
		System.out.println(customerArray);
		for (NonprofitCustomer c : customerArray) {
			System.out.println(c);
		}

		int[] testScores = new int[3];
		testScores[0] = 97;
		testScores[1] = -7;
		testScores[2] = 1;
		for (int i = 0; i < testScores.length; i++) {
			System.out.println(testScores[i]);
		}

		System.out.println(Arrays.binarySearch(testScores, -7));

		int[] marks = { -7, 1, 97 };

		System.out.println(Arrays.compare(testScores, marks));
		System.out.println(Arrays.mismatch(testScores, marks));

		System.out.println(Arrays.equals(testScores, marks));
		Arrays.sort(testScores);
		System.out.println(Arrays.equals(testScores, marks));

	}

}
