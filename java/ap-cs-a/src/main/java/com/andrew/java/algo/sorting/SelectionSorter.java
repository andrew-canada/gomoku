package com.andrew.java.algo.sorting;

import java.util.Arrays;

import com.andrew.java.algo.array.DebugDuck;

public class SelectionSorter {
    private SelectionSorter() {
    }

    private static void swap(DebugDuck[] ducks, int index1, int index2) {
        DebugDuck temp = ducks[index1];
        ducks[index1] = ducks[index2];
        ducks[index2] = temp;
    }

    public static DebugDuck[] sortDuckArr(DebugDuck[] ducks) {
        DebugDuck[] sortedDucks = Arrays.copyOf(ducks, ducks.length);
        for (int outerIndex = 0; outerIndex < sortedDucks.length; outerIndex++) {
            int minIndex = outerIndex;
            for (int innerIndex = outerIndex + 1; innerIndex < sortedDucks.length; innerIndex++) {
                if (sortedDucks[innerIndex].compareTo(sortedDucks[minIndex]) < 0) {
                    minIndex = innerIndex;
                }
            }
            if (minIndex != outerIndex) {
                swap(sortedDucks, outerIndex, minIndex);
            }
        }
        return sortedDucks;
    }
}
