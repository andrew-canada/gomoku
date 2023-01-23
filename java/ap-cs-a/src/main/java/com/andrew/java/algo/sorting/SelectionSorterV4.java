package com.andrew.java.algo.sorting;

import java.util.List;
import java.util.stream.Collectors;

public class SelectionSorterV4 {

    private SelectionSorterV4() {
    }

    public static List<CashDonor> selectionSort(List<CashDonor> donors) {
        List<CashDonor> sortedDonors = donors.stream().collect(Collectors.toList());
        int listSize = sortedDonors.size();
        int minDonorIndex;
        for (int i = 0; i < listSize - 1; i++) {
            minDonorIndex = i;
            for (int j = i + 1; j < listSize; j++) {
                if (sortedDonors.get(j).compareTo(sortedDonors.get(minDonorIndex)) < 0) {
                    minDonorIndex = j;
                }
            }
            if (minDonorIndex != i) {
                ElementSwapper.swapDonorList(sortedDonors, minDonorIndex, i);
            }
        }
        return sortedDonors;
    }

}
