package com.andrew.java.algo.array;

import java.util.Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class ArrayShifterTest {

	ArrayShifter as;
	int[] inputArr = { 1, 2, 3, 4, 5 };
	int[] shiftRightOnceArr = { 5, 1, 2, 3, 4 };
	int[] shiftRight3Arr = { 3, 4, 5, 1, 2 };

	int[] shiftLeftOnceArr = { 2, 3, 4, 5, 1 };
	int[] shiftLeft3Arr = { 4, 5, 1, 2, 3 };

	@BeforeEach
	void setup() {
		as = new ArrayShifter();
	}

	@Test
	void testShiftArrayRight() {
		Arrays.stream(as.shiftArrayRight(inputArr, 1)).forEach(System.out::print);
		Assertions.assertArrayEquals(shiftRightOnceArr, as.shiftArrayRight(inputArr, 1));

		Arrays.stream(as.shiftArrayRight(inputArr, 3)).forEach(System.out::print);
		Assertions.assertArrayEquals(shiftRight3Arr, as.shiftArrayRight(inputArr, 3));

		System.out.println();
	}

	@Test
	void testShiftArrayLeft() {
		System.out.println("left shifting");
		Arrays.stream(as.shiftArrayLeft(inputArr, 1)).forEach(System.out::print);
		Assertions.assertArrayEquals(shiftLeftOnceArr, as.shiftArrayLeft(inputArr, 1));

		Arrays.stream(as.shiftArrayLeft(inputArr, 3)).forEach(System.out::print);
		Assertions.assertArrayEquals(shiftLeft3Arr, as.shiftArrayLeft(inputArr, 3));
	}

}
