package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import com.andrew.java.algo.array.DebugDuck;

class InsertionSorterTest {

    List<DebugDuck> ducks = new ArrayList<>(
            Arrays.asList(new DebugDuck("d3", 3), new DebugDuck("d2", 2), new DebugDuck("d1", 1),
                    new DebugDuck("d4", 4)));
    List<DebugDuck> sortedDucks = new ArrayList<>(
            Arrays.asList(new DebugDuck("d1", 1), new DebugDuck("d2", 2), new DebugDuck("d3", 3),
                    new DebugDuck("d4", 4)));

    @Test
    void testSort() {
        List<DebugDuck> newSortedDucks = InsertionSorter.sort(ducks);
        newSortedDucks.stream().forEach(System.out::print);

        Assertions.assertEquals(sortedDucks, newSortedDucks);
    }

}
