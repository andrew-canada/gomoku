package com.andrew.java.algo.sorting;

import java.util.List;

public class QuickSorterV6 {
	private QuickSorterV6() {
	}

	public static void quickSort(List<CardDonor> donors) {
		sort(donors, 0, donors.size() - 1);
	}

	public static void sort(List<CardDonor> donors, int low, int high) {
		if (low < high) {
			int partitionIndex = partition(donors, low, high);
			sort(donors, low, partitionIndex - 1);
			sort(donors, partitionIndex + 1, high);
		}
	}

	public static int partition(List<CardDonor> donors, int low, int high) {
		CardDonor partitionElem = donors.get(high);
		int i = low - 1;
		for (int j = 0; j <= high; j++) {
			if (donors.get(j).compareTo(partitionElem) < 0) {
				i++;
				ElementSwapper.swapCardDonorList(donors, i, j);
			}
		}
		ElementSwapper.swapCardDonorList(donors, i + 1, high);
		return i + 1;
	}
}
