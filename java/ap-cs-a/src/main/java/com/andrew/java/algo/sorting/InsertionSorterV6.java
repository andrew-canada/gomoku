package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class InsertionSorterV6 {
	private InsertionSorterV6() {
	}

	public static List<CardDonor> insertionSort(List<CardDonor> donors) {
		List<CardDonor> sorted = donors.stream().collect(Collectors.toList());
		CardDonor minDonor;
		for (int i = 1; i < sorted.size(); i++) {
			minDonor = sorted.get(i);
			int j = i - 1;
			while (j >= 0 && sorted.get(j).compareTo(minDonor) >= 0) {
				sorted.set(j + 1, sorted.get(j));
				j--;
			}
			sorted.set(j + 1, minDonor);
		}
		return sorted;
	}
}
