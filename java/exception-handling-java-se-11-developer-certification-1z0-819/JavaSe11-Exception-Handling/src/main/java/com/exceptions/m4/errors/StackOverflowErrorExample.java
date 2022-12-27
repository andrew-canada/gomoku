package com.exceptions.m4.errors;

public class StackOverflowErrorExample {

	static int i = 0;

	public static void main(String[] args) {

		calculate(1, 2);
	}

	private static void calculate(int a, int b) {
		System.out.println(i++);
		calculate(a, b);
	}
}
