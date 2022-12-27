package com.andrew.java.exam;

public class CheckDigit {

	//@formatter:off
	/** Returns the check digit for num, as described in part (a).
	* Precondition: The number of digits in num is between one and
	* six, inclusive.
	* num >= 0
	*/
	
	//@formatter:on
	public static int getNumberOfDigits(int num) {
		return 4;
	}

	public static int getDigit(int num, int n) {
		return 1;
	}

	public static int getCheck(int num) {
		int digits = getNumberOfDigits(num);
		int sum = 0;

		for (int i = digits; i > 0; i--) {
			sum += getDigit(num, i) * (i + 1);
		}

		return sum % 10;
	}
}
