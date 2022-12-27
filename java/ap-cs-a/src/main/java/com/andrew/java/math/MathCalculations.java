package com.andrew.java.math;

import java.util.ArrayList;
import java.util.List;

public class MathCalculations {

	public static void main(String[] args) {
		int[] ages = new int[3];
		ages[0] = 1;
		ages[1] = 2;
		ages[2] = 3;
		// can not add beyond fixed length
		// ages[3] = 4;

		// list has no fixed length
		List list = new ArrayList();
		list.add("hello");

		// Math Operations

		System.out.println(2 * 3);
		System.out.println(2 / 3D);
		System.out.println(2 % 3);
		// can't divide by 0
		// System.out.println(2 / 0);

		int x = 1;
		// first assigns value to y then adds to x
		int y = x++;

		// %d means that there will be a decimal integer
		System.out.printf("\nx = %d, y = %d\n", x, y);
		System.out.printf("x = %d\ny = %d\n", x, y);
		String firstname = "andrew";
		String lastname = "peng";
		// %s means that there will be a string
		System.out.printf("First Name: %s\nLast Name: %s\n", firstname, lastname);
		System.out.println(x);
		System.out.println(y);
		// first adds to x then assigns value to y
		y = ++x;
		System.out.println(x);
		System.out.println(y);
		x += 4;
		System.out.println("x equals x + 4: " + x);
		x -= 4;
		System.out.println("x equals x - 4: " + x);
		x *= 4;
		System.out.println("x equals x * 4: " + x);
		x /= 4;
		System.out.println("x equals x / 4: " + x);
		x %= 4;
		System.out.println("x equals x % 4: " + x);

	}

}
