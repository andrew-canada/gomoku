package com.andrew.java.algo.sorting;

import java.util.Arrays;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class DonorSelectionSorterTest {

    Donor[] donorsByName = { new Donor("bob", 500), new Donor("joe", 1), new Donor("john", 350),
            new Donor("steve", -55), new Donor("steve", -55), new Donor("steve", -55), new Donor("steve", -55) };
    Donor[] donorsByDonation = { new Donor("bob", 500), new Donor("john", 350), new Donor("joe", 1),
            new Donor("steve", -55), new Donor("steve", -55), new Donor("steve", -55), new Donor("steve", -55) };

    @Test
    void testSortDonerArr() {
        Donor[] sortedDonorsByDonation = DonorSelectionSorter.sortDonerArr(donorsByName);
        Arrays.stream(sortedDonorsByDonation).forEach(System.out::println);
        Assertions.assertArrayEquals(sortedDonorsByDonation, donorsByDonation);
    }

}
