package com.andrew.ap.java.classes.comparing;

public class HouseTester {

    public static void main(String[] args) {
        House h1 = new House("blue", 1200, 4);
        House h2 = new House("blue", 1200, 4);
        House h3 = h1;
        House h4 = new House("red", 1200, 4);

        System.out.println(h1.equals(h4));
        System.out.println(h1.equals(h2));
        System.out.println(h1.equals(h3));

    }

}
