package com.andrew.ap.java.array;

import java.awt.Color;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class TwoDimArrMethodsTest {

    boolean[][] matrix = { { true, false, false }, { true, true, false } };
    Color[][] picture = { { Color.BLUE, Color.BLUE, Color.BLUE }, { Color.BLUE, Color.RED, Color.BLUE },
            { Color.BLUE, Color.RED, Color.BLUE } };
    Color[][] bluePicture = { { Color.BLUE, Color.BLUE, Color.BLUE }, { Color.BLUE, Color.BLUE, Color.BLUE },
            { Color.BLUE, Color.BLUE, Color.BLUE } };

    @Test
    void testPercentTrue() {
        Assertions.assertEquals(0.5, TwoDimArrMethods.percentTrue(matrix));
    }

    @Test
    void testFindFirstNonBlueColumn() {
        Assertions.assertEquals(1, TwoDimArrMethods.findFirstNonBlueColumn(picture));
        Assertions.assertEquals(-1, TwoDimArrMethods.findFirstNonBlueColumn(bluePicture));
    }

}
