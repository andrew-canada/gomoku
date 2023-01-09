package com.andrew.java.algo.sorting;

import java.util.Arrays;

public class MergeSorterV1 {
    private MergeSorterV1() {
    }

    public static void mergeSort(int[] numbers) {
        int length = numbers.length;
        if (length < 2) {
            return;
        }
        int mid = (length - 1) / 2;
        int[] leftArr = Arrays.copyOfRange(numbers, 0, mid + 1);
        int[] rightArr = Arrays.copyOfRange(numbers, mid + 1, length);
        mergeSort(leftArr);
        mergeSort(rightArr);
        merge(numbers, leftArr, rightArr);
    }

    private static void merge(int[] numbers, int[] leftArr, int[] rightArr) {
        int leftLength = leftArr.length;
        int rightLength = rightArr.length;
        int indexToInsert = 0;
        int leftIndex = 0;
        int rightIndex = 0;
        while (leftIndex < leftLength && rightIndex < rightLength) {
            if (leftArr[leftIndex] < rightArr[rightIndex]) {
                numbers[indexToInsert] = leftArr[leftIndex];
                leftIndex += 1;
                indexToInsert += 1;
            } else if (rightArr[rightIndex] < leftArr[leftIndex]) {
                numbers[indexToInsert] = rightArr[rightIndex];
                rightIndex += 1;
                indexToInsert += 1;
            } else {
                numbers[indexToInsert] = rightArr[rightIndex];
                numbers[indexToInsert + 1] = leftArr[leftIndex];
                rightIndex += 1;
                leftIndex += 1;
                indexToInsert += 2;
            }
        }
        while (leftIndex < leftLength) {
            numbers[indexToInsert] = leftArr[leftIndex];
            leftIndex += 1;
            indexToInsert += 1;
        }
        while (rightIndex < rightLength) {
            numbers[indexToInsert] = rightArr[rightIndex];
            rightIndex += 1;
            indexToInsert += 1;
        }
    }
}
