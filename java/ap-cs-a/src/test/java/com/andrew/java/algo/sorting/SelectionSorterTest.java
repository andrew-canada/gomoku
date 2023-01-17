package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import com.andrew.java.algo.array.DebugDuck;

class SelectionSorterTest {

    DebugDuck[] unsortedDucks = { new DebugDuck("d3", 3), new DebugDuck("d2", 2), new DebugDuck("d1", 1) };
    DebugDuck[] sortedDucks = { new DebugDuck("d1", 1), new DebugDuck("d2", 2), new DebugDuck("d3", 3) };
    int[] nums = { 1, 7, 8, 6, 4, 2, 7, 4 };
    List<Student> students = new ArrayList<>(Arrays.asList(new Student(123, "joe"), new Student(400, "john"),
            new Student(-600, "bob"), new Student(0, "steve"), new Student(0, "no")));

    @Test
    void testSortDuckArr() {
        DebugDuck[] newSortedDucks = SelectionSorter.sortDuckArr(unsortedDucks);
        Arrays.stream(newSortedDucks).forEach(System.out::print);

        Assertions.assertArrayEquals(sortedDucks, newSortedDucks);
    }

    @Test
    void testSelectionSortV1() {
        Assertions.assertArrayEquals(new int[] { 1, 2, 4, 4, 6, 7, 7, 8 }, SelectionSorterV1.selectionSort(nums));
    }

    @Test
    void testSelectionSortV2() {
        Assertions.assertArrayEquals(new int[] { 1, 2, 4, 4, 6, 7, 7, 8 }, SelectionSorterV2.selectionSort(nums));
    }

    @Test
    void testSelectionSortV4() {
        List<Student> sortedStudents = SelectionSorterV3.selectionSort(students);
        Assertions.assertEquals(Arrays.asList(new Student(-600, "bob"), new Student(0, "steve"),
                new Student(0, "no"),
                new Student(123, "joe"), new Student(400, "john")), sortedStudents);
        sortedStudents.stream().forEach(System.out::println);
    }

}
