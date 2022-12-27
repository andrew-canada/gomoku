package com.andrew.ap.java.array;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class ArrayManipulatorTest {

    ArrayManipulator am;
    ArrayManipulator evenAM;
    int[] numbers = { 1, 2, 3, 4, 5 };
    int[] evenList = { 1, 2, 3, 4 };

    @BeforeEach
    void setUp() throws Exception {
        am = new ArrayManipulator(5);
        am.setList(numbers);
        evenAM = new ArrayManipulator(4);
        evenAM.setList(evenList);
    }

    @Test
    void testArrayManipulator() {
        ArrayManipulator newAM = new ArrayManipulator(5);
        newAM.setList(numbers);
        Assertions.assertEquals(am, newAM);
    }

    @Test
    void testGetMiddleIndex() {
        Assertions.assertEquals(2, am.getMiddleIndex());
        Assertions.assertEquals(1, evenAM.getMiddleIndex());

    }

    @Test
    void testGetAvgStream() {
        Assertions.assertEquals(3, am.getAvgStream());
    }

    @Test
    void testGetAvgForLoop() {
        Assertions.assertEquals(3, am.getAvgForLoop());
    }

}
