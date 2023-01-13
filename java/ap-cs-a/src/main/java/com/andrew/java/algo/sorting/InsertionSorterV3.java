package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class InsertionSorterV3 {
	private InsertionSorterV3() {
	}

	public static List<Student> insertionSort(List<Student> students) {
		List<Student> sortedStudents = students.stream().collect(Collectors.toList());
		Student minStudent;
		for (int i = 1; i < sortedStudents.size(); i++) {
			minStudent = sortedStudents.get(i);
			int j = i - 1;
			while (j >= 0 && sortedStudents.get(j).compareTo(minStudent) > 0) {
				sortedStudents.set(j + 1, sortedStudents.get(j));
				j -= 1;
			}
			sortedStudents.set(j + 1, minStudent);
		}
		return sortedStudents;
	}
}
