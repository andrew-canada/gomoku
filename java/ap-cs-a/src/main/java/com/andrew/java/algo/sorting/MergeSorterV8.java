package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.List;

public class MergeSorterV8 {
	private MergeSorterV8() {
	}

	public static void mergeSort(List<CardDonor> donors) {
		int listSize = donors.size();
		if (listSize >= 2) {
			int mid = (listSize - 1) / 2;
			List<CardDonor> left = new ArrayList<>(donors.subList(0, mid + 1));
			List<CardDonor> right = new ArrayList<>(donors.subList(mid + 1, listSize));
			mergeSort(left);
			mergeSort(right);
			merge(donors, left, right);
		}
	}

	public static void merge(List<CardDonor> donors, List<CardDonor> left, List<CardDonor> right) {
		int size = donors.size();
		int leftSize = left.size();
		int rightSize = right.size();
		int indexToInsert = 0;
		int leftIndex = 0;
		int rightIndex = 0;
		CardDonor leftDonor;
		CardDonor rightDonor;

		while (leftIndex < leftSize && rightIndex < rightSize) {
			leftDonor = left.get(leftIndex);
			rightDonor = right.get(rightIndex);
			if (leftDonor.compareTo(rightDonor) < 0) {
				donors.set(indexToInsert, leftDonor);
				leftIndex++;
				indexToInsert++;
			} else if (rightDonor.compareTo(leftDonor) < 0) {
				donors.set(indexToInsert, rightDonor);
				rightIndex++;
				indexToInsert++;
			} else {
				donors.set(indexToInsert, rightDonor);
				donors.set(indexToInsert + 1, rightDonor);
				rightIndex++;
				leftIndex++;
				indexToInsert += 2;
			}
		}
		while (leftIndex < leftSize) {
			donors.set(indexToInsert, left.get(leftIndex));
			leftIndex++;
			indexToInsert++;
		}
		while (rightIndex < rightSize) {
			donors.set(indexToInsert, right.get(rightIndex));
			rightIndex++;
			indexToInsert++;
		}
	}
}
