package com.andrew.java.algo.searching;

public class SequentialSearcherV1 {
    private SequentialSearcherV1() {
    }

    public static int searchUnsorted(int[] numbers, int numberToFind) {
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == numberToFind) {
                return i;
            }
        }
        return -1;
    }

    public static int searchSortedAscending(int[] numbers, int numberToFind) {
        if (numberToFind < numbers[0] || numberToFind > numbers[numbers.length - 1]) {
            return -1;
        }
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] == numberToFind) {
                return i;
            }
        }
        return -1;
    }
}
