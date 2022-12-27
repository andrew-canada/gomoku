package com.andrew.java.math;

import java.security.SecureRandom;

public class MathClass {

	public static void main(String[] args) {
		// Math.round rounds the number up or down
		System.out.println(Math.round(24.5));
		// Math.ceil returns the smallest integer greater than or equal to the argument
		// If the argument is an integer, it prints the argument as a double
		System.out.println(Math.ceil(2));
		System.out.println(Math.ceil(2.1));
		// Math.floor returns the largest integer less than or equal to the argument
		System.out.println(Math.floor(7.9));
		// Math.max returns the greater of 2 double values
		System.out.println(Math.max(2, 5));
		// Math.min returns the smallest of 2 double values
		System.out.println(Math.min(4, 1));
		// Math.random returns a double greater than or equal to 0.0 and less than 1.0
		System.out.println(Math.random());
		// Multiplying Math.random bye 100 returns a double greater than or equal to 0.0
		// and less than 100
		System.out.println(Math.random() * 100);
		SecureRandom sr = new SecureRandom();
		System.out.println(sr.nextInt());

	}

}
