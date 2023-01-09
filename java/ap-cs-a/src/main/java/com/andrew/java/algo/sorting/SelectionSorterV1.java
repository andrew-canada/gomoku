package com.andrew.java.algo.sorting;

import java.util.Arrays;

public class SelectionSorterV1 {
    private SelectionSorterV1() {
    }

    public static int[] selectionSort(int[] nums) {
        int[] sortedNums = Arrays.copyOf(nums, nums.length);
        int minIndex;
        for (int i = 0; i < sortedNums.length - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < sortedNums.length; j++) {
                if (sortedNums[j] < sortedNums[minIndex]) {
                    minIndex = j;
                }
            }
            ElementSwapper.swap(sortedNums, i, minIndex);
        }
        return sortedNums;
    }
}
