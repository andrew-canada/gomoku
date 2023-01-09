package com.andrew.java.algo.sorting;

import java.util.Arrays;

public class MergeSorterOld {
    private MergeSorterOld() {
    }

    public static void mergeSort(int[] numbers) {
        if (numbers.length < 2) {
            return;
        }
        int length = numbers.length;
        int middleIndex = (length - 1) / 2;
        int[] leftArr = Arrays.copyOfRange(numbers, 0, middleIndex + 1);
        int[] rightArr = Arrays.copyOfRange(numbers, middleIndex + 1, length);
        mergeSort(leftArr);
        mergeSort(rightArr);
        merge(numbers, leftArr, rightArr);
    }

    private static void merge(int[] numbers, int[] leftArr, int[] rightArr) {

        int indexToInsert = 0;
        int leftCounter = 0;
        int rightCounter = 0;
        while (leftCounter < leftArr.length && rightCounter < rightArr.length) {
            if (leftArr[leftCounter] > rightArr[rightCounter]) {
                numbers[indexToInsert] = rightArr[rightCounter];
                indexToInsert += 1;
                rightCounter += 1;
            } else if (leftArr[leftCounter] < rightArr[rightCounter]) {
                numbers[indexToInsert] = leftArr[leftCounter];
                indexToInsert += 1;
                leftCounter += 1;
            } else {
                numbers[indexToInsert] = leftArr[leftCounter];
                numbers[indexToInsert + 1] = leftArr[leftCounter];
                indexToInsert += 2;
                leftCounter += 1;
                rightCounter += 1;
            }
        }
        while (leftCounter < leftArr.length) {
            numbers[indexToInsert] = leftArr[leftCounter];
            indexToInsert += 1;
            leftCounter += 1;
        }
        while (rightCounter < rightArr.length) {
            numbers[indexToInsert] = rightArr[rightCounter];
            indexToInsert += 1;
            rightCounter += 1;
        }
    }
}
