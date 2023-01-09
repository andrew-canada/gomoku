package com.andrew.ap.java.recursion;

import java.util.ArrayList;
import java.util.Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ReverseEvenFinderTest {

    @Test
    void testFindEven() {
        Assertions.assertEquals(new ArrayList<Integer>(Arrays.asList(10, 8, 6)),
                ReverseEvenFinder.findEven(new ArrayList<Integer>(Arrays.asList(1, 6, 3, 7, 8, 10, -999))));
    }

}
