package com.andrew.ap.java.recursion;

import java.util.List;

public class RecursiveMethods2 {
    private RecursiveMethods2() {
    }

    public static int sum1(int input) {
        if (input <= 0) {
            return 0;
        }
        return input + sum1(input / 2);
    }

    public static int sum2(int input) {
        if (input <= 0) {
            return 0;
        }
        return input + sum2(input / 2) + sum2(input / 3);
    }

    public static int countOccurrences1(List<Integer> numberList, int numberToFind, int startPos) {
        if (startPos >= numberList.size()) {
            return 0;
        }
        if (numberToFind == numberList.get(startPos)) {
            return 1 + countOccurrences1(numberList, numberToFind, startPos + 1);
        } else {
            return countOccurrences1(numberList, numberToFind, startPos + 1);
        }
    }

    public static int countOccurrences2(List<Integer> numberList, int numberToFind) {
        if (numberList.isEmpty()) {
            return 0;
        }
        int currentNumber = numberList.remove(0);
        if (currentNumber == numberToFind) {
            return 1 + countOccurrences2(numberList, numberToFind);
        } else {
            return countOccurrences2(numberList, numberToFind);
        }
    }
}
