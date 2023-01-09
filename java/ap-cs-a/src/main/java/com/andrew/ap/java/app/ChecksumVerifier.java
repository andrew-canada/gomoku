package com.andrew.ap.java.app;

public class ChecksumVerifier {
    private ChecksumVerifier() {
    }

    private static int sumFirstThreeDigits(int fourDigitNumber) {
        int sum = 0;
        fourDigitNumber = fourDigitNumber / 10;
        sum += fourDigitNumber % 10;
        fourDigitNumber = fourDigitNumber / 10;
        sum += fourDigitNumber % 10;
        fourDigitNumber = fourDigitNumber / 10;
        sum += fourDigitNumber % 10;
        return sum;
    }

    public static boolean checkIfValid(int fourDigitNumber) {
        if (fourDigitNumber < 1000 || fourDigitNumber > 9999) {
            return false;
        } else {
            return sumFirstThreeDigits(fourDigitNumber) % 7 == fourDigitNumber % 10;
        }
    }
}
