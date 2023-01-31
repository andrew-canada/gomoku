package com.andrew.ap.java.recursion;

import java.util.List;

public class RecursiveMethods {
	private RecursiveMethods() {
	}

	public static int sum1(int num) {
		if (num <= 0) {
			return 0;
		}
		return num + sum1(num / 2);
	}

	public static int sum2(int num) {
		if (num <= 0) {
			return 0;
		}
		return num + sum2(num / 2) + sum2(num / 3);
	}

	public static int countOccurrences1(List<Integer> nums, int numberToFind, int startPos) {
	}

}
