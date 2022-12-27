package com.andrew.ap.java.classes.wrapper;

public class WrapperClassTester {

    public static void main(String[] args) {
        int int1 = 5;
        double double1 = 3;

        @SuppressWarnings({ "deprecation", "removal" })
        Integer num1 = new Integer(int1);
        Integer num2 = 10;

        Double wrappedDouble1 = 10.0;
        // Double wrappedDouble2 = 10;

        System.out.println(num1);
        System.out.println(num2);

        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.MAX_VALUE + 1);
        System.out.println(Integer.MIN_VALUE);

        Integer intAvg = (int1 + num2) / 2;
        int primitiveAvg = intAvg.intValue();

        System.out.println(intAvg);
        System.out.println(primitiveAvg);

        Double doubleAvg = (double1 + wrappedDouble1) / 2;
        double primitiveAvg2 = doubleAvg.doubleValue();

        System.out.println(doubleAvg);
        System.out.println(primitiveAvg2);

    }

}
