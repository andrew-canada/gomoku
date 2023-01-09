package com.andrew.java.algo.arraylist;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ProductSummerTest {

    int[] numArr = { 1, 2, 3, 4, 5 };
    List<Integer> numList = new ArrayList<>(Arrays.asList(7, 6, 5, 4, 3, 2, 1));

    @Test
    void testGetProductSum() {
        Assertions.assertEquals(65, ProductSummer.getProductSum(numList, numArr));
    }

    @Test
    void testGetProducts() {
        Assertions.assertArrayEquals(new int[] { 7, 12, 15, 16, 15, 2, 1 }, ProductSummer.getProducts(numList, numArr));
    }

}
