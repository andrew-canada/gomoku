package com.andrew.java.loops;

import java.util.Arrays;

public class Test {

	public static void main(String[] args) {
		int[] numbers = { 1, 2, 3, 4, 5 };
		int sum = 0;
		for (int number : numbers) {

			sum = sum + number;
			if (number == 2) {
				continue;
			}
		}
		System.out.println(sum);

		sum = 0;
		for (int number : numbers) {
			if (number == 2) {
				continue;
			}
			sum = sum + number;

		}
		System.out.println(sum);

		sum = 0;
		for (int number : numbers) {

			sum = sum + number;
			if (number == 2) {
				break;
			}
		}
		System.out.println(sum);

		sum = 0;
		for (int number : numbers) {
			if (number == 2) {
				break;
			}
			sum = sum + number;

		}
		System.out.println(sum);
		System.out.println(Arrays.stream(numbers).sum());
		System.out.println(Arrays.stream(numbers).map(input -> input * 2).sum());
	}

}
