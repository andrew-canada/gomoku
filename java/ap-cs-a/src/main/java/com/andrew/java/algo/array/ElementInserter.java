package com.andrew.java.algo.array;

public class ElementInserter {
    private ElementInserter() {
    }

    public static int insert(int[] nums, int numToInsert) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > numToInsert) {
                for (int j = nums.length - 1; j > i; j--) {
                    nums[j] = nums[j - 1];
                }
                nums[i] = numToInsert;
                return i;
            }
        }
        return -1;
    }
}
