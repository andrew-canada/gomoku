package com.andrew.java.algo.arraylist;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ConcurrentModifier {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>(Arrays.asList(1, 2, 3));
        for (Integer i : numbers) {
            if (i == 1) {
                numbers.add(0);
            }
        }

        for (Integer i : numbers) {
            if (i == 1) {
                numbers.remove(0);
            }
        }
    }
}
