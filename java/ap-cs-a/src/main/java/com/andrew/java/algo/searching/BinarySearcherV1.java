package com.andrew.java.algo.searching;

public class BinarySearcherV1 {
    private BinarySearcherV1() {
    }

    public static int searchIteratively(int[] nums, int numToFind) {
        int low = 0;
        int high = nums.length - 1;
        int mid = (low + high) / 2;
        while (low <= mid) {
            if (nums[mid] == numToFind) {
                return mid;
            } else if (nums[mid] < numToFind) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            mid = (low + high) / 2;
        }
        return -1;
    }

    public static int searchRecursively(int[] nums, int numToFind) {
        return recursiveSearch(nums, numToFind, 0, nums.length - 1);
    }

    private static int recursiveSearch(int[] nums, int numToFind, int low, int high) {
        if (low > high) {
            return -1;
        }
        int mid = (low + high) / 2;
        if (nums[mid] == numToFind) {
            return mid;
        } else if (nums[mid] < numToFind) {
            return recursiveSearch(nums, numToFind, mid + 1, high);
        } else {
            return recursiveSearch(nums, numToFind, low, mid - 1);
        }
    }
}
