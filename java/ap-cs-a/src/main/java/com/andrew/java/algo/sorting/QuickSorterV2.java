package com.andrew.java.algo.sorting;

public class QuickSorterV2 {
    private QuickSorterV2() {
    }

    public static void quickSort(int[] numbers) {
        sort(numbers, 0, numbers.length - 1);
    }

    private static void sort(int[] numbers, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(numbers, low, high);
            sort(numbers, low, pivotIndex - 1);
            sort(numbers, pivotIndex + 1, high);
        }
    }

    private static int partition(int[] numbers, int low, int high) {
        int pivotElement = numbers[high];
        int i = low - 1;
        for (int j = low; j <= high; j++) {
            if (numbers[j] < pivotElement) {
                i += 1;
                ElementSwapper.swap(numbers, i, j);
            }
        }
        ElementSwapper.swap(numbers, i + 1, high);
        return i + 1;
    }

}
