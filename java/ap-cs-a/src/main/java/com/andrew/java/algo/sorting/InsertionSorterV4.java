package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class InsertionSorterV4 {
	private InsertionSorterV4() {
	}

	public static List<CashDonor> insertionSort(List<CashDonor> donors) {
		List<CashDonor> sortedDonors = donors.stream().collect(Collectors.toList());
		int listSize = sortedDonors.size();
		CashDonor minDonor;
		for (int i = 1; i < listSize; i++) {
			minDonor = sortedDonors.get(i);
			int j = i - 1;
			while (j >= 0 && minDonor.compareTo(sortedDonors.get(j)) < 0) {
				sortedDonors.set(j + 1, sortedDonors.get(j));
				j -= 1;
			}
			sortedDonors.set(j + 1, minDonor);
		}
		return sortedDonors;
	}
}
