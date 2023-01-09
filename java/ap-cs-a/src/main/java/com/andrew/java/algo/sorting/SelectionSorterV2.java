package com.andrew.java.algo.sorting;

import java.util.Arrays;

public class SelectionSorterV2 {
    private SelectionSorterV2() {
    }

    public static int[] selectionSort(int[] nums) {
        int[] sortedNums = Arrays.copyOf(nums, nums.length);
        for (int i = 0; i < nums.length - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < nums.length; j++) {
                if (sortedNums[j] < sortedNums[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                ElementSwapper.swap(sortedNums, i, minIndex);
            }
        }
        return sortedNums;
    }
}
