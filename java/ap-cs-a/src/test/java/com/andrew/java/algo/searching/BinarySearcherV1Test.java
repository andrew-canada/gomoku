package com.andrew.java.algo.searching;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class BinarySearcherV1Test {

    int[] sortedNumbers = { 1, 2, 3, 5, 6 };
    int[] unsortedNumbers = { 1, 5, 3, 2, 6 };

    @Test
    void testIterativeBinarySearch() {
        Assertions.assertEquals(0, BinarySearcherV1.searchIteratively(sortedNumbers, 1));
        Assertions.assertEquals(4, BinarySearcherV1.searchIteratively(sortedNumbers, 6));
        Assertions.assertEquals(2, BinarySearcherV1.searchIteratively(sortedNumbers, 3));

        Assertions.assertEquals(2, BinarySearcherV1.searchIteratively(unsortedNumbers, 3));
    }

    @Test
    void testResursiveBinarySearch() {
        Assertions.assertEquals(0, BinarySearcherV1.searchRecursively(sortedNumbers, 1));
        Assertions.assertEquals(4, BinarySearcherV1.searchRecursively(sortedNumbers, 6));
        Assertions.assertEquals(2, BinarySearcherV1.searchRecursively(sortedNumbers, 3));

        Assertions.assertEquals(2, BinarySearcherV1.searchIteratively(unsortedNumbers, 3));
    }

}
