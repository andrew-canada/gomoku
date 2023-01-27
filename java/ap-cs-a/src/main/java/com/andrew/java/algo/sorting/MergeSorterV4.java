package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.List;

public class MergeSorterV4 {
	private MergeSorterV4() {
	}

	public static void mergeSort(List<CashDonor> donors) {
		int listSize = donors.size();
		if (listSize >= 2) {
			int mid = (listSize - 1) / 2;
			List<CashDonor> left = new ArrayList<>(donors.subList(0, mid + 1));
			List<CashDonor> right = new ArrayList<>(donors.subList(mid + 1, listSize));
			mergeSort(left);
			mergeSort(right);
			merge(donors, left, right);
		}
	}

	private static void merge(List<CashDonor> donors, List<CashDonor> left, List<CashDonor> right) {
		int leftIndex = 0, rightIndex = 0, indexToInsert = 0;
		int leftLength = left.size(), rightLength = right.size();
		CashDonor leftDonor, rightDonor;

		while (leftIndex < leftLength && rightIndex < rightLength) {
			leftDonor = left.get(leftIndex);
			rightDonor = right.get(rightIndex);

			if (leftDonor.compareTo(rightDonor) < 0) {
				donors.set(indexToInsert, leftDonor);
				leftIndex += 1;
				indexToInsert += 1;
			} else if (rightDonor.compareTo(leftDonor) < 0) {
				donors.set(indexToInsert, rightDonor);
				rightIndex += 1;
				indexToInsert += 1;
			} else {
				donors.set(indexToInsert, rightDonor);
				donors.set(indexToInsert + 1, rightDonor);
				rightIndex += 1;
				leftIndex += 1;
				indexToInsert += 2;
			}
		}

		while (leftIndex < leftLength) {
			donors.set(indexToInsert, left.get(leftIndex));
			indexToInsert += 1;
			leftIndex += 1;
		}

		while (rightIndex < rightLength) {
			donors.set(indexToInsert, right.get(rightIndex));
			indexToInsert += 1;
			rightIndex += 1;
		}
	}
}
