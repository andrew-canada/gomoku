package com.andrew.ap.java.recursion;

public class MaxFinder {
    private MaxFinder() {

    }

    public static int findMax(int[] numbers, int currentIndex) {
        int currentNumber;
        if (currentIndex == 1) {
            return numbers[0];
        } else {
            currentNumber = findMax(numbers, currentIndex - 1);
            if (currentNumber > numbers[currentIndex]) {
                return currentNumber;
            } else {
                return numbers[currentIndex];
            }
        }

    }
}
