package com.andrew.ap.java.array;

public class SquareMatrixManipulator {
    private SquareMatrixManipulator() {
    }

    public static int sumRow(int[][] matrix, int row) {
        int sum = 0;
        for (int i = 0; i < matrix.length; i++) {
            sum += matrix[row][i];
        }
        return sum;
    }

    public static int sumColumn(int[][] matrix, int column) {
        int sum = 0;
        for (int i = 0; i < matrix.length; i++) {
            sum += matrix[i][column];
        }
        return sum;
    }

    public static int sumMinorDiagonal(int[][] matrix) {
        int sum = 0;
        int length = matrix.length;
        for (int i = length - 1; i >= 0; i--) {
            sum += matrix[i][length - i - 1];
        }
        return sum;
    }

    public static int sumMajorDiagonal(int[][] matrix) {
        int sum = 0;
        for (int i = 0; i < matrix.length; i++) {
            sum += matrix[i][i];
        }
        return sum;
    }

    // magic square has sum of all rows, columns, and diagonals equal
    public static boolean checkIfMagic(int[][] matrix) {
        int sampleSum = sumRow(matrix, 0);
        for (int i = 0; i < matrix.length; i++) {
            if (sampleSum != sumColumn(matrix, i) || sampleSum != sumRow(matrix, i)) {
                return false;
            }
        }
        return sampleSum == sumMinorDiagonal(matrix) && sampleSum == sumMajorDiagonal(matrix);
    }

}
