package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class InsertionSorterV1 {
    private InsertionSorterV1() {
    }

    public static List<Student> insertionSort(List<Student> students) {
        List<Student> sortedStudents = students.stream().collect(Collectors.toList());
        for (int i = 1; i < sortedStudents.size(); i++) {
            Student minStudent = sortedStudents.get(i);
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
