package com.andrew.collections;

import java.util.ArrayList;
import java.util.List;

public class GenericWidget<T> {

	// @formatter:off
	// naming conventions:
	/*
	 * E: element 
	 * K: key 
	 * T: type V: value S, U, V, ...: 2nd, third, fourth... types
	 */
	// @formatter:on
	public static void main(String[] args) {
		GenericWidget<String> w1 = new GenericWidget<>();
		System.out.println(w1.getType());
		w1.setType("words");

		System.out.println(w1.getType());

		String[] countries = new String[] { "kazakhstan", "uganda" };
		System.out.println(GenericWidget.getFirstWord(countries));

		List letters = new ArrayList<String>();
		letters.add("a");
		letters.add("b");
		printElements(letters);
		printBoundedElements(letters);

	}

	private T type;

	public T getType() {
		return type;
	}

	public void setType(T type) {
		this.type = type;
	}

	public static <T> T getFirstWord(T[] inputArray) {
		if (inputArray.length > 0) {
			return inputArray[0];
		}
		return null;
	}

	// generic wildcard takes any type
	public static void printElements(List<?> inputList) {
		inputList.forEach(System.out::println);
	}

	// generic wildcard can be bounded
	public static void printBoundedElements(List<? extends String> inputList) {
		inputList.forEach(System.out::println);
	}
}
