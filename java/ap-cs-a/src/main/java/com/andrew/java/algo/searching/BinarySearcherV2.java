package com.andrew.java.algo.searching;

import java.util.List;

import com.andrew.java.algo.sorting.Student;

public class BinarySearcherV2 {
	private BinarySearcherV2() {
	}

	public static int binarySearchRecursive(List<Student> students, Student target) {
		return recursiveSearch(students, target, 0, students.size() - 1);
	}

	private static int recursiveSearch(List<Student> students, Student target, int low, int high) {
		if (low > high) {
			return -1;
		}
		int mid = (low + high) / 2;
		if (target.compareTo(students.get(mid)) < 0) {
			return recursiveSearch(students, target, low, mid + 1);
		} else if (target.compareTo(students.get(mid)) > 0) {
			return recursiveSearch(students, target, mid + 1, high);
		} else {
			return mid;
		}
	}

	public static int binarySearchIterative(List<Student> students, Student target) {
		int low = 0;
		int high = students.size() - 1;
		int mid;
		while (low <= high) {
			mid = (low + high) / 2;
			if (target.compareTo(students.get(mid)) < 0) {
				high = mid;
			} else if (target.compareTo(students.get(mid)) > 0) {
				low = mid + 1;
			} else {
				return mid;
			}
		}
		return -1;
	}
}
