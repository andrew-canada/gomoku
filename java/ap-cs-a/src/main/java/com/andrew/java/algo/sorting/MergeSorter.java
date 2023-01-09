package com.andrew.java.algo.sorting;

import java.util.Arrays;

public class MergeSorter {
	private MergeSorter() {
	}

	public static void mergeSort(int[] numbers) {
		if (numbers.length < 2) {
			return;
		}
		int length = numbers.length;
		int middle = (numbers.length - 1) / 2;
		int[] leftArr = Arrays.copyOfRange(numbers, 0, middle + 1);
		int[] rightArr = Arrays.copyOfRange(numbers, middle + 1, length);
		mergeSort(leftArr);
		mergeSort(rightArr);
		merge(numbers, leftArr, rightArr);
	}

	public static void merge(int[] numbers, int[] leftArr, int[] rightArr) {
		int insertionIndex = 0;
		int leftIndex = 0, rightIndex = 0;
		int leftLength = leftArr.length;
		int rightLength = rightArr.length;
		while (leftIndex < leftLength && rightIndex < rightLength) {
			int leftVal = leftArr[leftIndex];
			int rightVal = rightArr[rightIndex];
			if (leftVal > rightVal) {
				numbers[insertionIndex] = rightVal;
				rightIndex += 1;
				insertionIndex += 1;
			} else if (rightVal > leftVal) {
				numbers[insertionIndex] = leftVal;
				leftIndex += 1;
				insertionIndex += 1;
			} else {
				numbers[insertionIndex] = leftVal;
				numbers[insertionIndex + 1] = leftVal;
				leftIndex += 1;
				rightIndex += 1;
				insertionIndex += 2;
			}
		}
		if (leftIndex < leftLength) {
			while (leftIndex < leftLength) {
				numbers[insertionIndex] = leftArr[leftIndex];
				leftIndex += 1;
				insertionIndex += 1;
			}
		} else if (rightIndex < rightLength) {
			while (rightIndex < rightLength) {
				numbers[insertionIndex] = rightArr[rightIndex];
				rightIndex += 1;
				insertionIndex += 1;
			}
		}
	}
}
