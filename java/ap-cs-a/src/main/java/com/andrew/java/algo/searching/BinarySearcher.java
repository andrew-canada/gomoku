package com.andrew.java.algo.searching;

public class BinarySearcher {
    private BinarySearcher() {
    }

    public static int loopSearch(int[] numbers, int lowIndex, int highIndex, int numToFind) {
        int middleIndex;
        while (lowIndex <= highIndex) {
            middleIndex = (lowIndex + highIndex) / 2;
            if (numToFind > numbers[middleIndex]) {
                lowIndex = middleIndex + 1;
            } else if (numToFind < numbers[middleIndex]) {
                highIndex = middleIndex - 1;
            } else {
                return middleIndex;
            }
        }
        return -1;
    }

    public static int recursiveSearch(int[] numbers, int lowIndex, int highIndex, int numToFind) {
        if (lowIndex > highIndex) {
            return -1;
        }
        int middleIndex = (lowIndex + highIndex) / 2;
        if (numToFind > numbers[middleIndex]) {
            return recursiveSearch(numbers, middleIndex + 1, highIndex, numToFind);
        } else if (numToFind < numbers[middleIndex]) {
            return recursiveSearch(numbers, lowIndex, middleIndex - 1, numToFind);
        } else {
            return middleIndex;
        }
    }
}
