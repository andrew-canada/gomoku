package com.andrew.java.loops;

public class ForLoops {

	public static void main(String[] args) {
		for (int i = 0; i < 5; i++) {
			System.out.println("Hello World" + i);
		}

		System.out.println();

		for (int i = 1; i <= 5; i++) {
			System.out.println("Hello World" + i);
		}

		for (int i = 1; i <= 5; ++i) {
			System.out.println("Hello World" + i);
		}
	}
}
// When know how many times to execute one or more statements, use for loop
// When don'g know how many times want to repeat something, use while; e.g. user enters sometimes until type quit (quit = terminate). 
// How many times type things that aren't "quit" is unknown.
