package com.andrew.ap.java.array;

public class TwoDimArrTest {

    public static void main(String[] args) {
        String[][] arr = { { "My", "A" }, { "AP", "Class" }, { "CS", "Rocks!" } };

        for (int i = 0; i < arr[0].length; i++) {
            for (int j = 0; j < arr.length; j++) {
                System.out.print(arr[j][i] + " ");
            }
        }
    }

}
