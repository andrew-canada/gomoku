package com.andrew.ap.java.array;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class NumberShufflerTest {

    int[] oddLengthNumbers = { 1, 2, 3, 4, 5 };
    int[] evenLengthNumbers = { 1, 2, 3, 4 };

    @Test
    void testShuffle() {
        Assertions.assertArrayEquals(new int[] { 1, 4, 2, 5, 3 }, NumberShuffler.shuffle(oddLengthNumbers));
        Assertions.assertArrayEquals(new int[] { 1, 3, 2, 4 }, NumberShuffler.shuffle(evenLengthNumbers));
    }

}
