package com.andrew.java.algo.sorting;

import java.util.Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import com.andrew.java.algo.sorting.MergeSorter;

class MergeSorterTest {

    int[] numbers1 = { 4, 3, 2, 1 };
    int[] numbers2 = { 4, 3, 3, 2, 1 };
    int[] numbers3 = { -4, 182, 0, 1, -9 };
    int[] numbers4 = {};

    @Test
    void testSort() {
        MergeSorter.mergeSort(numbers1);
        Arrays.stream(numbers1).forEach(System.out::print);
        System.out.println();
        Assertions.assertArrayEquals(new int[] { 1, 2, 3, 4 }, numbers1);

        MergeSorter.mergeSort(numbers2);
        Arrays.stream(numbers2).forEach(System.out::print);
        System.out.println();
        Assertions.assertArrayEquals(new int[] { 1, 2, 3, 3, 4 }, numbers2);

        MergeSorter.mergeSort(numbers3);
        Arrays.stream(numbers3).forEach(System.out::print);
        System.out.println();
        Assertions.assertArrayEquals(new int[] { -9, -4, 0, 1, 182 }, numbers3);

        MergeSorter.mergeSort(numbers4);
        Arrays.stream(numbers4).forEach(System.out::print);
        System.out.println();
        Assertions.assertArrayEquals(new int[] {}, numbers4);
    }

}
