package com.andrew.java.algo.searching;

import java.util.List;

import com.andrew.java.algo.sorting.CashDonor;

public class LinearSearcherV4 {
	private LinearSearcherV4() {
	}

	public static int linearSearchUnsorted(List<CashDonor> donors, CashDonor target) {
		for (int i = 0; i < donors.size(); i++) {
			if (donors.get(i).equals(target)) {
				return i;
			}
		}
		return -1;
	}

	public static int linearSearchSorted(List<CashDonor> donors, CashDonor target) {
		int listSize = donors.size();
		if (target.compareTo(donors.get(0)) < 0 || target.compareTo(donors.get(listSize - 1)) > 0) {
			return -1;
		}
		for (int i = 0; i < listSize; i++) {
			if (donors.get(i).equals(target)) {
				return i;
			}
		}
		return -1;
	}
}
