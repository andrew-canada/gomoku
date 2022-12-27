package com.andrew.ap.java.classes.math;

public class MathClassTester {

    public static void main(String[] args) {
        int num1 = 5;
        int num2 = -5;
        double num3 = -23.54;

        System.out.println(Math.abs(num1));
        System.out.println(Math.abs(num2));
        System.out.println(Math.abs(num3));

        System.out.println(Math.pow(2, -2));
        System.out.println(Math.pow(2, 2));

        System.out.println(Math.sqrt(-4));
        System.out.println(Math.sqrt(4));
        System.out.println(Math.sqrt(2));

        System.out.println(Math.random());
        System.out.println((int) (Math.random() * 100));

    }

}
