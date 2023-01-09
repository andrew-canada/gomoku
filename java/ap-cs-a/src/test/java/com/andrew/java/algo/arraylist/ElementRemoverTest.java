package com.andrew.java.algo.arraylist;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ElementRemoverTest {

    List<Integer> nums = new ArrayList<>(Arrays.asList(1, 3, 2, 4, 5, 2));

    @Test
    void testRemoveWithWhile() {
        Assertions.assertEquals(2, ElementRemover.removeWithWhile(nums, 2));
        nums.stream().forEach(System.out::print);
        System.out.println();
    }

    @Test
    void testRemoveWithFor() {
        nums.stream().forEach(System.out::print);
        Assertions.assertEquals(2, ElementRemover.removeWithFor(nums, 2));
        System.out.println();
        nums.stream().forEach(System.out::print);
    }

}
