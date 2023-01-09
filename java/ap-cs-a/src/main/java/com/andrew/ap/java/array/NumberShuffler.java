package com.andrew.ap.java.array;

import java.util.Arrays;

public class NumberShuffler {
    private NumberShuffler() {
    }

    public static int[] shuffle(int[] numbers) {
        int length = numbers.length;
        int[] tempNums = new int[length];
        int midIndex = (length - 1) / 2;
        int indexToInsert = 0;
        int indexToAccess = 0;
        while (indexToAccess <= midIndex) {
            tempNums[indexToInsert] = numbers[indexToAccess];
            indexToInsert += 2;
            indexToAccess += 1;
        }
        indexToInsert = 1;
        while (indexToAccess < length) {
            tempNums[indexToInsert] = numbers[indexToAccess];
            indexToInsert += 2;
            indexToAccess += 1;
        }
        numbers = Arrays.copyOf(tempNums, length);
        return numbers;
    }
}
