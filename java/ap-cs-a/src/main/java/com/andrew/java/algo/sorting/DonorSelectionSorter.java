package com.andrew.java.algo.sorting;

import java.util.Arrays;

public class DonorSelectionSorter {

    private DonorSelectionSorter() {
    }

    private static void swap(Donor[] donors, int index1, int index2) {
        Donor tempDonor = donors[index1];
        donors[index1] = donors[index2];
        donors[index2] = tempDonor;
    }

    public static Donor[] sortDonerArr(Donor[] donors) {
        Donor[] sortedDonorArr = Arrays.copyOf(donors, donors.length);
        int arrLength = sortedDonorArr.length;
        int maxDonationIndex;
        for (int i = 0; i < arrLength; i++) {
            maxDonationIndex = i;
            for (int j = i + 1; j < arrLength; j++) {
                if (donors[j].compareTo(donors[maxDonationIndex]) > 0) {
                    maxDonationIndex = j;
                }
            }
            if (maxDonationIndex != i) {
                swap(sortedDonorArr, i, maxDonationIndex);
            }
            System.out.println("number of outer loop iterations: " + (i + 1));
            System.out.println("current max: " + donors[maxDonationIndex]);
        }
        return sortedDonorArr;
    }
}
