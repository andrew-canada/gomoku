package com.andrew.java.algo.searching;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class BinarySearcherP1Test {

    int[] numbers = { 1, 3, 5, 7, 9, 15 };

    @Test
    void testLoopBinarySearch() {
        Assertions.assertEquals(0, BinarySearcherP1.loopBinarySearch(numbers, 1));
        Assertions.assertEquals(4, BinarySearcherP1.loopBinarySearch(numbers, 9));
        Assertions.assertEquals(-1, BinarySearcherP1.loopBinarySearch(numbers, 111));
    }

    @Test
    void testRecursiveBinarySearch() {
        Assertions.assertEquals(0, BinarySearcherP1.recursiveBinarySearch(numbers, 1));
        Assertions.assertEquals(4, BinarySearcherP1.recursiveBinarySearch(numbers, 9));
        Assertions.assertEquals(-1, BinarySearcherP1.recursiveBinarySearch(numbers, 111));
    }

}
