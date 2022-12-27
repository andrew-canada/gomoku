package com.andrew.java.algo.array;

import java.util.Arrays;

public class ArrayShifter {

	public int[] shiftArrayRight(int[] inputArr, int numberOfShifts) {
		int[] shiftedArr = new int[inputArr.length];
		for (int i = 0; i < inputArr.length; i++) {
			shiftedArr[Math.abs(numberOfShifts + i) % inputArr.length] = inputArr[i];
		}
		return shiftedArr;
	}

	public int[] shiftArrayLeft(int[] inputArr, int numberOfShifts) {
		int[] shiftedArr = Arrays.copyOf(inputArr, inputArr.length);

		for (int i = 0; i < numberOfShifts; i++) {
			int lastVal = shiftedArr[0];
			for (int j = 0; j < inputArr.length - 1; j++) {
				shiftedArr[j] = shiftedArr[j + 1];
			}
			shiftedArr[inputArr.length - 1] = lastVal;
		}
		return shiftedArr;
	}
}
