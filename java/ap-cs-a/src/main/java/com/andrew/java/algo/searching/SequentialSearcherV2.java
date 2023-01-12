package com.andrew.java.algo.searching;

import java.util.List;

import com.andrew.java.algo.sorting.Student;

public class SequentialSearcherV2 {
	private SequentialSearcherV2() {
	}

	public static int sequentialSearchUnsorted(List<Student> students, Student target) {
		for (int i = 0; i < students.size(); i++) {
			if (students.get(i).equals(target)) {
				return i;
			}
		}
		return -1;
	}

	public static int sequentialSearchSorted(List<Student> students, Student target) {
		int listSize = students.size();
		if (target.compareTo(students.get(0)) < 0 || target.compareTo(students.get(listSize - 1)) > 0) {
			return -1;
		}
		for (int i = 0; i < listSize; i++) {
			if (students.get(i).equals(target)) {
				return i;
			}
		}
		return -1;
	}
}
