package com.andrew.java.algo.sorting;

public class QuickSorterV1 {
    private QuickSorterV1() {
    }

    public static void quickSort(int[] nums) {
        sort(nums, 0, nums.length - 1);
    }

    private static void sort(int[] nums, int low, int high) {
        if (low >= high) {
            return;
        }
        int pivotIndex = partition(nums, low, high);
        sort(nums, low, pivotIndex - 1);
        sort(nums, pivotIndex + 1, high);
    }

//    private static int partition(int[] nums, int low, int high) {
//        int pivotIndex = 0;
//        int pivotElement = nums[low];
//        int j = high;
//        for (int i = low; i <= high; i++) {
//            if (nums[i] > pivotElement) {
//                while (j >= 0) {
//                    if (nums[j] < pivotElement) {
//                        ElementSwapper.swap(nums, i, j);
//                        pivotIndex = i + 1;
//                        j -= 1;
//                        break;
//                    }
//                }
//            }
//        }
//        ElementSwapper.swap(nums, pivotIndex, 0);
//        return pivotIndex;
//    }

    private static int partition(int[] nums, int low, int high) {
        int pivotElement = nums[low];
        int smallElementIndex = low;
        for (int i = high; i >= low; i--) {
            if (nums[i] <= pivotElement) {
                smallElementIndex = i;
                break;
            }
        }
        for (int j = smallElementIndex - 1; j >= low; j--) {
            if (nums[j] > pivotElement) {
                ElementSwapper.swap(nums, j, smallElementIndex);
                smallElementIndex -= 1;
            }
        }
        ElementSwapper.swap(nums, smallElementIndex, low);
        return smallElementIndex;
    }

}
