package com.andrew.java.algo.searching;

import java.util.List;

import com.andrew.java.algo.sorting.CashDonor;

public class BinarySearcherV4 {
	private BinarySearcherV4() {
	}

	public static int binarySearchRecursively(List<CashDonor> donors, CashDonor target) {
		return binarySearch(donors, target, 0, donors.size());
	}

	private static int binarySearch(List<CashDonor> donors, CashDonor target, int low, int high) {
		if (low > high) {
			return -1;
		}
		int mid = (low + high) / 2;
		if (donors.get(mid).equals(target)) {
			return mid;
		} else if (donors.get(mid).compareTo(target) < 0) {
			return binarySearch(donors, target, mid + 1, high);
		} else {
			return binarySearch(donors, target, low, mid - 1);
		}
	}

	public static int binarySearchIteratively(List<CashDonor> donors, CashDonor target) {
		int mid;
		int low = 0;
		int high = donors.size();
		while (low <= high) {
			mid = (low + high) / 2;
			if (donors.get(mid).equals(target)) {
				return mid;
			} else if (donors.get(mid).compareTo(target) < 0) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		return -1;
	}
}
