package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class SelectionSorterV5 {
	private SelectionSorterV5() {
	}

	public static List<CashDonor> selectionSort(List<CashDonor> donors) {
		int minIndex;
		List<CashDonor> sortedDonors = donors.stream().collect(Collectors.toList());
		int listSize = donors.size();
		for (int i = 0; i < listSize - 1; i++) {
			minIndex = i;
			for (int j = i + 1; j < listSize; j++) {
				if (sortedDonors.get(j).compareTo(sortedDonors.get(minIndex)) < 0) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				ElementSwapper.swapDonorList(sortedDonors, minIndex, i);
			}
		}
		return sortedDonors;
	}
}
