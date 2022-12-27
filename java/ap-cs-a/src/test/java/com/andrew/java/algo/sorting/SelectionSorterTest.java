package com.andrew.java.algo.sorting;

import java.util.Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import com.andrew.java.algo.array.DebugDuck;

class SelectionSorterTest {

    DebugDuck[] unsortedDucks = { new DebugDuck("d3", 3), new DebugDuck("d2", 2), new DebugDuck("d1", 1) };
    DebugDuck[] sortedDucks = { new DebugDuck("d1", 1), new DebugDuck("d2", 2), new DebugDuck("d3", 3) };

    @Test
    void testSortDuckArr() {
        DebugDuck[] newSortedDucks = SelectionSorter.sortDuckArr(unsortedDucks);
        Arrays.stream(newSortedDucks).forEach(System.out::print);

        Assertions.assertArrayEquals(sortedDucks, newSortedDucks);
    }

}
