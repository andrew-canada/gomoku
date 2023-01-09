package com.andrew.java.algo.arraylist;

import java.util.List;

public class ElementRemover {
    private ElementRemover() {
    }

    public static int removeWithWhile(List<Integer> numbers, int numToRemove) {
        int numRemoved = 0;
        int i = 0;
        while (i < numbers.size()) {
            if (numbers.get(i) == numToRemove) {
                numbers.remove(i);
                numRemoved += 1;
            } else {
                i += 1;
            }
        }
        return numRemoved;
    }

    public static int removeWithFor(List<Integer> numbers, int numToRemove) {
        int numRemoved = 0;
        for (int i = numbers.size() - 1; i >= 0; i--) {
            if (numbers.get(i) == numToRemove) {
                numbers.remove(i);
                numRemoved += 1;
            }
        }
        return numRemoved;
    }
}
