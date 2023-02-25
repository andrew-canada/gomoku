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
		}
	}

	private static int partition(List<CashDonor> donorList, int low, int high) {
		return -1;
	}
}
