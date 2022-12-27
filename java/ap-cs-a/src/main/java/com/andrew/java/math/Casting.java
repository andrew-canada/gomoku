package com.andrew.java.math;

public class Casting {

	public static void main(String[] args) {
		double x = 2.9;
		// casting (int) converts double x into int
		// casting into int ignores the decimals (2.9 turns into 2)
		int y = (int) x + 4;
		System.out.println(y);

		String A = "3";
		// Integer is wrapper class
		// Integer.parseInt converts String A into int ("3" turns into 3)
		int b = Integer.parseInt(A) + 5;
		System.out.println(b);

		String C = "3.5";
		// Double.parseDouble converts String A into double ("3.5" turns into 3.5)
		// Integer is part of double (any int value can be stored in a double)
		// Java implicitly (automatically) converts 5 into 5.0
		// Implicit casting happens when there will be no transferred data loss
		double d = Double.parseDouble(C) + 5;
		System.out.println(d);

		// Java gives the value of the short to an anonymous int, then adds the int
		// value to the other int.
		short o = 3;
		int k = o + 5;
		System.out.println(k);

		long n = 42_949_672_960L;
		int i = (int) n + 1;
		System.out.println("implicit and explicit casting don't work for numbers out of range of the conversion unit. "
				+ n + " (long) casting into int : " + (int) n);
	}

}
