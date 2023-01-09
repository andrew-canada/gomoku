package com.andrew.ap.java.recursion;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ReverseStringTest {

    @Test
    void testGetReverse() {
        Assertions.assertEquals("dlrow olleh", ReverseString.getReverse("hello world"));
    }

}
