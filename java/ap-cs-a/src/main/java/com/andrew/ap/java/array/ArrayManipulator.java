package com.andrew.ap.java.array;

import java.util.Arrays;

public class ArrayManipulator {
    private int[] list;

    public ArrayManipulator(int numElements) {
        list = new int[numElements];
    }

    public int getMiddleIndex() {
        if (list.length % 2 == 0) {
            return list.length / 2 - 1;
        } else {
            return list.length / 2;
        }
    }

    public double getAvgStream() {
        return Arrays.stream(list).average().orElse(-1);
    }

    public double getAvgForLoop() {
        double total = 0;
        for (int element : list) {
            total += element;
        }
        return total / list.length;
    }

    public int[] getList() {
        return list;
    }

    public void setList(int[] list) {
        this.list = list;
    }

    @Override
    public boolean equals(Object otherObj) {
        if (this == otherObj) {
            return true;
        }
        return otherObj instanceof ArrayManipulator am && this.getList() == am.getList();
    }
}
