package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class SelectionSorterV3 {

    private SelectionSorterV3() {
    }

    public static List<Student> selectionSort(List<Student> students) {
        List<Student> sortedStudents = students.stream().collect(Collectors.toList());
        int minIndex;
        for (int i = 0; i < sortedStudents.size() - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < sortedStudents.size(); j++) {
                if (sortedStudents.get(j).compareTo(sortedStudents.get(minIndex)) < 0) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                ElementSwapper.swapList(sortedStudents, minIndex, i);
            }
        }
        return sortedStudents;
    }

}
