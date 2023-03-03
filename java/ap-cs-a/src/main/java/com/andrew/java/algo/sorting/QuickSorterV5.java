package com.andrew.java.algo.sorting;

import java.util.List;

public class QuickSorterV5 {

	private QuickSorterV5() {
	}

	public static void quickSort(List<CashDonor> donorList) {
		sort(donorList, 0, donorList.size() - 1);
	}

	private static void sort(List<CashDonor> donorList, int low, int high) {
		if (low < high) {
			int partitionIndex = partition(donorList, low, high);
			sort(donorList, low, partitionIndex - 1);
			sort(donorList, partitionIndex + 1, high);
		}
	}

	private static int partition(List<CashDonor> donorList, int low, int high) {
		CashDonor partitionElem = donorList.get(high);
		int i = low - 1;
		for (int j = 0; j <= high; j++) {
			if (donorList.get(j).compareTo(partitionElem) < 0) {
				i++;
				ElementSwapper.swapDonorList(donorList, i, j);
			}
		}
		ElementSwapper.swapDonorList(donorList, i + 1, high);
		return i + 1;
	}
}
