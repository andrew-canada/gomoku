package com.andrew.java.algo.searching;

import com.andrew.java.algo.sorting.Student;

public class LinearSearcherV3 {
	private LinearSearcherV3() {
	}

	public static int linearSearchUnsorted(Student[] students, Student target) {
		for (int i = 0; i < students.length; i++) {
			if (students[i].equals(target)) {
				return i;
			}
		}
		return -1;
	}

	public static int linearSearchSorted(Student[] students, Student target) {
		int arrLength = students.length;
		if (target.compareTo(students[0]) < 0 || target.compareTo(students[arrLength - 1]) > 0) {
			return -1;
		}
		for (int i = 0; i < arrLength; i++) {
			if (students[i].equals(target)) {
				return i;
			}
		}
		return -1;
	}
}
