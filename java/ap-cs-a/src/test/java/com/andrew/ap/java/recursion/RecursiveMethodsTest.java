package com.andrew.ap.java.recursion;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class RecursiveMethodsTest {

    List<Integer> numbers = new ArrayList<>(Arrays.asList(1, 2, 2, 3, 4, 4, 4));

    @Test
    void testSum1() {
        Assertions.assertEquals(16, RecursiveMethods.sum1(9));
    }

    @Test
    void testSum2() {
        Assertions.assertEquals(22, RecursiveMethods.sum2(9));
    }

    @Test
    void testCountOccurrences1() {
        Assertions.assertEquals(3, RecursiveMethods.countOccurrences1(numbers, 4, 0));
        Assertions.assertEquals(0, RecursiveMethods.countOccurrences1(numbers, 1, 1));
        // Assertions.assertEquals(0, RecursiveMethods.countOccurrences1(numbers, 1,
        // -1));
        Assertions.assertEquals(0, RecursiveMethods.countOccurrences1(numbers, 1, 100));
    }

    @Test
    void testCountOccurrences2() {
        System.out.println(numbers);
        Assertions.assertEquals(3, RecursiveMethods.countOccurrences2(numbers, 4));
        System.out.println(numbers);
    }

}
