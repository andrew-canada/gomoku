package com.andrew.java.loops;

public class ForEachLoops {

	public static void main(String[] args) {
		String[] fruits = { "Apple", "Orange", "Banana", "Mango" };
		for (int i = 0; i < fruits.length; i++) {
			System.out.println(fruits[i]);
		}
		// in each iteration, fruit will hold the value of 1 item in the array.
		// No counter/boolean expression needed.
		for (String fruit : fruits) {
			System.out.println(fruit);
		}
	}

}
//for-each is for iterating
//for-each can't go backwards
//for-each can't access index