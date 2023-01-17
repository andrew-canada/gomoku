package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.List;

public class MergeSorterV3 {

    private MergeSorterV3() {
    }

    public static void mergeSort(List<Student> students) {
        int listSize = students.size();
        if (listSize >= 2) {
            int mid = (listSize - 1) / 2;
            List<Student> left = new ArrayList<>(students.subList(0, mid + 1));
            List<Student> right = new ArrayList<>(students.subList(mid + 1, listSize));
            mergeSort(left);
            mergeSort(right);
            merge(students, left, right);
        }
    }

    private static void merge(List<Student> students, List<Student> left, List<Student> right) {
        int indexToInsert = 0;
        int leftIndex = 0;
        int rightIndex = 0;
        int leftLength = left.size();
        int rightLength = right.size();
        Student leftStudent;
        Student rightStudent;
        while (leftIndex < leftLength && rightIndex < rightLength) {
            leftStudent = left.get(leftIndex);
            rightStudent = right.get(rightIndex);
            if (leftStudent.compareTo(rightStudent) < 0) {
                students.set(indexToInsert, leftStudent);
                leftIndex += 1;
                indexToInsert += 1;
            } else if (rightStudent.compareTo(leftStudent) < 0) {
                students.set(indexToInsert, rightStudent);
                rightIndex += 1;
                indexToInsert += 1;
            } else {
                students.set(indexToInsert, rightStudent);
                students.set(indexToInsert + 1, rightStudent);
                rightIndex += 1;
                leftIndex += 1;
                indexToInsert += 2;
            }
        }
        while (leftIndex < leftLength) {
            students.set(indexToInsert, left.get(leftIndex));
            leftIndex += 1;
            indexToInsert += 1;
        }
        while (rightIndex < rightLength) {
            students.set(indexToInsert, right.get(rightIndex));
            rightIndex += 1;
            indexToInsert += 1;
        }
    }

}
