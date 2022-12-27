package com.andrew.ap.java.loops;

public class ForLoopTester {

    public static void main(String[] args) {
        double total = 200;
        for (int numYears = 1; numYears <= 50; numYears++) {
            total *= 1.1;
        }
        System.out.println(total);
    }

}
