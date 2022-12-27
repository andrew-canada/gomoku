package com.andrew.ap.java.classes;

public class BillCalculator {

    private BillCalculator() {
    }

    public static double getAmtPerPerson(int numPeople, double totalPrice) {
        return totalPrice / numPeople;
    }
}
