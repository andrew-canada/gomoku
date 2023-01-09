package com.andrew.java.algo.searching;

public class BinarySearcherP1 {
    private BinarySearcherP1() {
    }

    public static int loopBinarySearch(int[] numbers, int numToFind) {
        int low = 0;
        int high = numbers.length - 1;
        int mid;
        while (low != high) {
            mid = (low + high) / 2;
            if (numbers[mid] == numToFind) {
                return mid;
            } else if (numbers[mid] < numToFind) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }
        return -1;
    }

    private static int search(int[] numbers, int numToFind, int low, int high) {
        int mid = (low + high) / 2;
        if (low > high) {
            return -1;
        } else if (numToFind == numbers[mid]) {
            return mid;
        } else if (numToFind < numbers[mid]) {
            return search(numbers, numToFind, low, mid - 1);
        } else {
            return search(numbers, numToFind, mid + 1, high);
        }
    }

    public static int recursiveBinarySearch(int[] numbers, int numToFind) {
        return search(numbers, numToFind, 0, numbers.length - 1);
    }
}
