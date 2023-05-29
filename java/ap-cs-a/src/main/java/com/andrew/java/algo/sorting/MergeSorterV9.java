package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.List;

public class MergeSorterV9 {
	private MergeSorterV9() {
	}

	public static void mergeSort(List<CardDonor> donors) {
		int donorSize = donors.size();
		if (donorSize > 1) {
			int mid = (donorSize - 1) / 2;
			List<CardDonor> left = new ArrayList<>(donors.subList(0, mid + 1));
			List<CardDonor> right = new ArrayList<>(donors.subList(mid + 1, donorSize + 1));
			mergeSort(left);
			mergeSort(right);
			merge(donors, left, right);
		}
	}

	public static void merge(List<CardDonor> donors, List<CardDonor> left, List<CardDonor> right) {
		int indexToInsert = 0;
	}
}
