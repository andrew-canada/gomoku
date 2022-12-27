package com.andrew.ap.java.array;

import java.awt.Color;

public class TwoDimArrMethods {
    private TwoDimArrMethods() {
    }

    public static double percentTrue(boolean[][] matrix) {
        double percentTrue = 0;
        int numTrue = 0;
        for (boolean[] arr : matrix) {
            for (boolean b : arr) {
                if (b) {
                    numTrue += 1;
                }
            }
        }
        percentTrue = numTrue / ((double) matrix.length * matrix[0].length);

        return percentTrue;
    }

    public static int findFirstNonBlueColumn(Color[][] picture) {
        for (int i = 0; i < picture[0].length; i++) {
            for (int j = 0; j < picture.length; j++) {
                if (!picture[j][i].equals(Color.BLUE)) {
                    return i;
                }
            }
        }
        return -1;
    }
}
