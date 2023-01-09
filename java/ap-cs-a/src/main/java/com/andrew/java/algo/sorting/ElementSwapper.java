package com.andrew.java.algo.sorting;

import java.util.List;

import com.andrew.ap.java.classes.T;

public class ElementSwapper {
    private ElementSwapper() {
    }

    public static void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    public static void swapList(List<T> elements, int index1, int index2) {
        T temp = elements.get(index1);
        elements.set(index1, elements.get(index2));
        elements.set(index2, temp);
    }
}
