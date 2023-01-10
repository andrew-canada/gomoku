package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.List;

public class MergeSorterV2 {
	private MergeSorterV2() {
	}

	public static void mergeSort(List<Student> students) {
		int length = students.size();
		if (length < 2) {
			return;
		}
		int mid = (students.size() - 1) / 2;
		List<Student> left = new ArrayList<>(students.subList(0, mid + 1));
		List<Student> right = new ArrayList<>(students.subList(mid + 1, students.size()));
		mergeSort(left);
		mergeSort(right);
		merge(students, left, right);
	}

	private static void merge(List<Student> students, List<Student> left, List<Student> right) {
		int leftIndex = 0;
		int rightIndex = 0;
		int indexToInsert = 0;
		int leftSize = left.size();
		int rightSize = right.size();

		while (leftIndex < leftSize && rightIndex < rightSize) {
			Student leftStudent = left.get(leftIndex);
			Student rightStudent = right.get(rightIndex);
			if (leftStudent.compareTo(rightStudent) < 0) {
				students.set(indexToInsert, leftStudent);
				indexToInsert += 1;
				leftIndex += 1;
			} else if (rightStudent.compareTo(leftStudent) < 0) {
				students.set(indexToInsert, rightStudent);
				indexToInsert += 1;
				rightIndex += 1;
			} else {
				students.set(indexToInsert, rightStudent);
				students.set(indexToInsert + 1, rightStudent);
				indexToInsert += 2;
				leftIndex += 1;
				rightIndex += 1;
			}
		}

		while (leftIndex < leftSize) {
			students.set(indexToInsert, left.get(leftIndex));
			leftIndex += 1;
			indexToInsert += 1;
		}
		while (rightIndex < rightSize) {
			students.set(indexToInsert, right.get(rightIndex));
			rightIndex += 1;
			indexToInsert += 1;
		}
	}
}
