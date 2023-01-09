package com.andrew.ap.java.array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class NumberInserterTest {

    List<Integer> numbers = new ArrayList<>(Arrays.asList(2, 1));

    @Test
    void testInsertNumber() {
        Assertions.assertEquals(new ArrayList<Integer>(Arrays.asList(3, 2, 1)),
                NumberInserter.insertNumber(numbers, 3));

        Assertions.assertEquals(new ArrayList<Integer>(Arrays.asList(3, 2, 1, 1)),
                NumberInserter.insertNumber(numbers, 1));

        Assertions.assertEquals(new ArrayList<Integer>(Arrays.asList(3, 2, 1, 1, 0)),
                NumberInserter.insertNumber(numbers, 0));
    }

}
