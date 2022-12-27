package com.andrew.ap.java.recursion;

import java.util.List;

public class RecursiveMethods1 {
    private RecursiveMethods1() {
    }

    public static void printNTimes(String s, int n) {
//        if (n == 0) {
//            return;
//        }
//        System.out.print(n);
//        System.out.println(s);
//        printNTimes(s, n - 1);
        if (n > 1) {
            printNTimes(s, n - 1);
        }
        System.out.print(n);
        System.out.println(s);
    }

    public static int sum1(int n) {
        if (n == 0) {
            return 0;
        }
        return n + sum1(n / 2);
    }

    public static int sum2(int n) {
        if (n == 0) {
            return 0;
        }
        return n + sum2(n / 2) + sum2(n / 3);
    }

    public static int countOccurrences1(List<Integer> numbers, int numToFind, int index) {
        if (index >= numbers.size() || index < 0) {
            return 0;
        }
        if (numbers.get(index) == numToFind)
            return countOccurrences1(numbers, numToFind, index + 1) + 1;
        return countOccurrences1(numbers, numToFind, index + 1);
    }

    public static int countOccurrences2(List<Integer> numbers, int numToFind) {
        if (numbers.isEmpty()) {
            return 0;
        }
        int numOccurrences = 0;
        int current = numbers.remove(0);
        if (current == numToFind) {
            numOccurrences += countOccurrences2(numbers, numToFind) + 1;
        } else {
            numOccurrences += countOccurrences2(numbers, numToFind);
        }
        numbers.add(0, current);
        return numOccurrences;
    }
}
