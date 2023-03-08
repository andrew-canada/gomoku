package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.List;

public class MergeSorterV7 {
	private MergeSorterV7() {
	}

	public static void mergeSort(List<CashDonor> donorList) {
		int listSize = donorList.size();
		if (listSize >= 2) {
			{
				int mid = (listSize - 1) / 2;
				List<CashDonor> left = new ArrayList<>(donorList.subList(0, mid + 1));
				List<CashDonor> right = new ArrayList<>(donorList.subList(mid + 1, listSize));
				mergeSort(left);
				mergeSort(right);
				merge(donorList, left, right);
			}
		}
	}

	public static void merge(List<CashDonor> donors, List<CashDonor> left, List<CashDonor> right) {
		int leftSize = left.size(), rightSize = right.size();
		int indexToInsert = 0, leftIndex = 0, rightIndex = 0;
		CashDonor leftDonor, rightDonor;
		while (leftIndex < leftSize && rightIndex < rightSize) {
			leftDonor = left.get(leftIndex);
			rightDonor = right.get(rightIndex);
			if (leftDonor.compareTo(rightDonor) < 0) {
				donors.set(indexToInsert, leftDonor);
				indexToInsert++;
				leftIndex++;
			} else if (rightDonor.compareTo(leftDonor) < 0) {
				donors.set(indexToInsert, rightDonor);
				indexToInsert++;
				rightIndex++;
			} else {
				donors.set(indexToInsert, leftDonor);
				donors.set(indexToInsert + 1, rightDonor);
				indexToInsert += 2;
				leftIndex++;
				rightIndex++;
			}
		}
		while (leftIndex < leftSize) {
			donors.set(indexToInsert, left.get(leftIndex));
			indexToInsert++;
			leftIndex++;
		}
		while (rightIndex < rightSize) {
			donors.set(indexToInsert, right.get(rightIndex));
			indexToInsert++;
			rightIndex++;
		}
	}
}
