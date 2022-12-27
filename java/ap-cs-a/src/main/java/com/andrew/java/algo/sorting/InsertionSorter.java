package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

import com.andrew.java.algo.array.DebugDuck;

public class InsertionSorter {
    private InsertionSorter() {
    }

    public static List<DebugDuck> sort(List<DebugDuck> ducks) {
        List<DebugDuck> newDucks = ducks.stream().collect(Collectors.toList());
        for (int outer = 1; outer < newDucks.size(); outer++) {
            DebugDuck minDuck = newDucks.get(outer);
            int inner = outer - 1;
            while (inner >= 0 && minDuck.compareTo(newDucks.get(inner)) < 0) {
                newDucks.set(inner + 1, newDucks.get(inner));
                inner -= 1;
            }
            newDucks.set(inner + 1, minDuck);
        }
        return newDucks;
    }
}
