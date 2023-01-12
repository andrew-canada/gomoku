package com.andrew.java.algo.sorting;

import java.util.List;

public class QuickSorterV3 {
	private QuickSorterV3() {
	}

	public static void quickSort(List<Student> students) {
		sort(students, 0, students.size() - 1);
	}

	public static void sort(List<Student> students, int low, int high) {
		if (low < high) {
			int partitionIndex = partition(students, low, high);
			sort(students, low, partitionIndex - 1);
			sort(students, partitionIndex + 1, high);
		}
	}

	public static int partition(List<Student> students, int low, int high) {
		Student pivotElement = students.get(high);
		int i = low - 1;
		for (int j = low; j <= high; j++) {
			if (students.get(j).compareTo(pivotElement) < 0) {
				i += 1;
				ElementSwapper.swapList(students, i, j);
			}
		}
		ElementSwapper.swapList(students, i + 1, high);
		return i + 1;
	}
}
