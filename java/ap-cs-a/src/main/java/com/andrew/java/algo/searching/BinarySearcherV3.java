package com.andrew.java.algo.searching;

import com.andrew.java.algo.sorting.Student;

public class BinarySearcherV3 {

    private BinarySearcherV3() {
    }

    public static int searchRecursively(Student[] students, Student target) {
        return search(students, 0, students.length - 1, target);
    }

    private static int search(Student[] students, int low, int high, Student target) {
        if (low > high) {
            return -1;
        }
        int mid = (low + high) / 2;
        if (students[mid].equals(target)) {
            return mid;
        } else if (students[mid].compareTo(target) < 0) {
            return search(students, mid + 1, high, target);
        } else {
            return search(students, low, mid - 1, target);
        }
    }

    public static int searchIteratively(Student[] students, Student target) {
        int mid;
        int low = 0;
        int high = students.length - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (students[mid].equals(target)) {
                return mid;
            } else if (students[mid].compareTo(target) < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

}
