package com.andrew.ap.java.recursion;

public class ExponentCalculator {
    private ExponentCalculator() {
    }

    public static double calculateExponent(int base, int exponent) {
        if (exponent == 0) {
            return 1;
        } else if (exponent > 0) {
            return base * calculateExponent(base, exponent - 1);
        } else {
            return (1.0 / base) * calculateExponent(base, exponent + 1);
        }
    }
}
