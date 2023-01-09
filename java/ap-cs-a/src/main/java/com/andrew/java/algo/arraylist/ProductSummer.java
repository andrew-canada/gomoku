package com.andrew.java.algo.arraylist;

import java.util.List;

public class ProductSummer {
    private ProductSummer() {
    }

    public static int getProductSum(List<Integer> list, int[] arr) {
        int sum = 0;
        for (int i = 0; i < list.size() && i < arr.length; i++) {
            sum += list.get(i) * arr[i];
        }
        return sum;
    }

    public static int[] getProducts(List<Integer> list, int[] arr) {
        int listSize = list.size();
        int arrLength = arr.length;
        int[] products = listSize > arrLength ? new int[listSize] : new int[arrLength];
        int index = 0;
        while (index < listSize && index < arrLength) {
            products[index] = list.get(index) * arr[index];
            index += 1;
        }

        while (index < listSize) {
            products[index] = list.get(index);
            index += 1;
        }
        while (index < arrLength) {
            products[index] = arr[index];
            index += 1;
        }

        return products;
    }
}
