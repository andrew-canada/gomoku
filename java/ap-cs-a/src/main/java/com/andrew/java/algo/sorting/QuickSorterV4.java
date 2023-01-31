package com.andrew.java.algo.sorting;

import java.util.List;

public class QuickSorterV4 {
	private QuickSorterV4() {
	}

	public static void quickSort(List<CashDonor> donors) {
		sort(donors, 0, donors.size() - 1);
	}

	private static void sort(List<CashDonor> donors, int low, int high) {
		if (low < high) {
			int partitionIndex = partition(donors, low, high);
			sort(donors, low, partitionIndex - 1);
			sort(donors, partitionIndex + 1, high);
		}
	}

	private static int partition(List<CashDonor> donors, int low, int high) {
		CashDonor partitionVal = donors.get(high);
		int i = low - 1;
		for (int j = 0; j <= high; j++) {
			if (donors.get(j).compareTo(partitionVal) < 0) {
				i += 1;
				ElementSwapper.swapDonorList(donors, i, j);
			}
		}
		ElementSwapper.swapDonorList(donors, i + 1, high);
		return i + 1;
	}
}
