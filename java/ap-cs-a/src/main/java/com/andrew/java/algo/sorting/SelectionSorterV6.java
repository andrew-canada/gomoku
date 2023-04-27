package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class SelectionSorterV6 {
	private SelectionSorterV6() {
	}

	public static List<CashDonor> selectionSort(List<CashDonor> donors) {
		List<CashDonor> sorted = donors.stream().collect(Collectors.toList());
		int listSize = donors.size();
		for (int i = 0; i < listSize - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < listSize; j++) {
				if (sorted.get(j).compareTo(sorted.get(minIndex)) < 0) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				ElementSwapper.swapDonorList(sorted, minIndex, i);
			}
		}
		return sorted;
	}
}
