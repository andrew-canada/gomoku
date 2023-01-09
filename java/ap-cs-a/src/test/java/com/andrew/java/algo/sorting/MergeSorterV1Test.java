package com.andrew.java.algo.sorting;

import java.util.Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class MergeSorterV1Test {

    int[] numbers = { 1, 5, 23, 5, 9, 6, 23, 1, 3, -1 };

    @Test
    void testMergeSort() {
        MergeSorterV1.mergeSort(numbers);
        Assertions.assertArrayEquals(new int[] { -1, 1, 1, 3, 5, 5, 6, 9, 23, 23 }, numbers);
        Arrays.stream(numbers).forEach(System.out::println);
    }

}
