package com.andrew.ap.java.recursion;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class MaxFinderTest {

    int numbers[] = { 1, 5, 3, 6, 9, 5, 3 };

    @Test
    void testFindMax() {
        Assertions.assertEquals(9, MaxFinder.findMax(numbers, 6));
    }

}
