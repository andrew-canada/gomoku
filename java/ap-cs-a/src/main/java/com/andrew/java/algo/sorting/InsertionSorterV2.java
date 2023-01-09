package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class InsertionSorterV2 {
    private InsertionSorterV2() {
    }

    public static List<KindergartenStudent> insertionSort(List<KindergartenStudent> students) {
        List<KindergartenStudent> sortedStudents = students.stream().collect(Collectors.toList());
        for (int i = 1; i < students.size(); i++) {
            KindergartenStudent minStudent = sortedStudents.get(i);
            int j = i - 1;
            while (j >= 0 && minStudent.compareTo(sortedStudents.get(j)) < 0) {
                sortedStudents.set(j + 1, sortedStudents.get(j));
                j -= 1;
            }
            sortedStudents.set(j + 1, minStudent);
        }
        return sortedStudents;
    }
}
