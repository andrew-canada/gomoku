package com.andrew.ap.java.recursion;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ExponentCalculatorTest {

    @Test
    void testCalculateExponent() {
        Assertions.assertEquals(1, ExponentCalculator.calculateExponent(10, 0));
        Assertions.assertEquals(8, ExponentCalculator.calculateExponent(2, 3));
        Assertions.assertEquals(1 / 8, ExponentCalculator.calculateExponent(2, -3));
    }

}
