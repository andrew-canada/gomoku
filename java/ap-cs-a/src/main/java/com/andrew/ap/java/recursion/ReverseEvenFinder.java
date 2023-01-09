package com.andrew.ap.java.recursion;

import java.util.ArrayList;
import java.util.List;

public class ReverseEvenFinder {
    private ReverseEvenFinder() {
    }

    public static List<Integer> findEven(List<Integer> numbers) {
        List<Integer> reverseEvens = new ArrayList<>();
        return findReverseEvens(numbers, 0, reverseEvens);
    }

    private static List<Integer> findReverseEvens(List<Integer> numbers, int currentIndex, List<Integer> reverseEvens) {
        if (numbers.get(currentIndex) == -999) {
            return reverseEvens;
        } else {
            currentIndex += 1;
            findReverseEvens(numbers, currentIndex, reverseEvens);
            if (numbers.get(currentIndex) % 2 == 0) {
                reverseEvens.add(numbers.get(currentIndex));
            }
        }
        return reverseEvens;
    }
}
