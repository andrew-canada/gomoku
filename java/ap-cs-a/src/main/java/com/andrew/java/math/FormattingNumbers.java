package com.andrew.java.math;

import java.text.NumberFormat;

public class FormattingNumbers {

	public static void main(String[] args) {
		System.out.println(NumberFormat.getCurrencyInstance().format(1643704873252.895));
		System.out.println(NumberFormat.getPercentInstance().format(0.4872));
	}

}
