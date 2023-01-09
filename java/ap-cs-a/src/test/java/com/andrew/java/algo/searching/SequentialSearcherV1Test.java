package com.andrew.java.algo.searching;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class SequentialSearcherV1Test {

    int[] unsortedNumbers = { 1, 5, 3, 2, 6 };
    int[] sortedNumbers = { 1, 2, 3, 5, 6 };

    @Test
    void testUnsortedSearch() {
        Assertions.assertEquals(0, SequentialSearcherV1.searchUnsorted(unsortedNumbers, 1));
        Assertions.assertEquals(4, SequentialSearcherV1.searchUnsorted(unsortedNumbers, 6));
        Assertions.assertEquals(2, SequentialSearcherV1.searchUnsorted(unsortedNumbers, 3));
    }

    @Test
    void testSortedAscendingSearch() {
        Assertions.assertEquals(-1, SequentialSearcherV1.searchSortedAscending(sortedNumbers, 0));
        Assertions.assertEquals(-1, SequentialSearcherV1.searchSortedAscending(sortedNumbers, 7));
        Assertions.assertEquals(0, SequentialSearcherV1.searchSortedAscending(sortedNumbers, 1));
    }

}
