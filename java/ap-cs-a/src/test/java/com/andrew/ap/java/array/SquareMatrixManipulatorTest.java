package com.andrew.ap.java.array;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class SquareMatrixManipulatorTest {

    int[][] squareMatrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int[][] magicSquare = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };

    @Test
    void testSumRow() {
        Assertions.assertEquals(6, SquareMatrixManipulator.sumRow(squareMatrix, 0));
    }

    @Test
    void testSumColumn() {
        Assertions.assertEquals(12, SquareMatrixManipulator.sumColumn(squareMatrix, 0));
    }

    @Test
    void testSumMinorDiagonal() {
        Assertions.assertEquals(15, SquareMatrixManipulator.sumMinorDiagonal(squareMatrix));
    }

    @Test
    void testSumMajorDiagonal() {
        Assertions.assertEquals(15, SquareMatrixManipulator.sumMajorDiagonal(squareMatrix));
    }

    @Test
    void testCheckIfMagic() {
        Assertions.assertEquals(false, SquareMatrixManipulator.checkIfMagic(squareMatrix));
        Assertions.assertEquals(true, SquareMatrixManipulator.checkIfMagic(magicSquare));
    }

}
