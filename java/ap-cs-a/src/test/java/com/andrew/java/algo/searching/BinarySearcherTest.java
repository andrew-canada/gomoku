package com.andrew.java.algo.searching;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class BinarySearcherTest {

    int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 42 };

    @Test
    void testLoopSearch() {
        Assertions.assertEquals(4, BinarySearcher.loopSearch(numbers, 0, numbers.length - 1, 5));
        Assertions.assertEquals(3, BinarySearcher.loopSearch(numbers, 0, numbers.length - 1, 4));
        Assertions.assertEquals(-1, BinarySearcher.loopSearch(numbers, 0, numbers.length - 1, 10));
    }

    @Test
    void testRecursiveSearch() {
        Assertions.assertEquals(4, BinarySearcher.recursiveSearch(numbers, 0, numbers.length - 1, 5));
        Assertions.assertEquals(3, BinarySearcher.recursiveSearch(numbers, 0, numbers.length - 1, 4));
        Assertions.assertEquals(-1, BinarySearcher.recursiveSearch(numbers, 0, numbers.length - 1, 14));
    }

}
