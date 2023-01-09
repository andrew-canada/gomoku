package com.andrew.ap.java.array;

import java.util.List;

public class NumberInserter {
    private NumberInserter() {
    }

    public static List<Integer> insertNumber(List<Integer> numbers, int number) {
        int indexToInsert = 0;
        while (indexToInsert < numbers.size() && number < numbers.get(indexToInsert)) {
            indexToInsert += 1;
        }
        numbers.add(indexToInsert, number);
        return numbers;
    }
}
