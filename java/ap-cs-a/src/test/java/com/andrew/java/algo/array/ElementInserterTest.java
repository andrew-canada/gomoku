package com.andrew.java.algo.array;

import java.util.Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ElementInserterTest {

    int[] nums = { 1, 3, 4, 5, -1 };

    @Test
    void testInsert() {
        Assertions.assertEquals(1, ElementInserter.insert(nums, 2));
        Arrays.stream(nums).forEach(System.out::print);
    }

}
