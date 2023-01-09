package com.andrew.java.algo.sorting;

public class DonorApp {

    public static void main(String[] args) {
        Donor d1 = new Donor("joe", 123);
        Donor d2 = new Donor(null, 123);

        System.out.println(d1.equals(d2));
        System.out.println(d2.equals(d1));

    }

}
