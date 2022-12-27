package com.andrew.ap.java.classes.passbyvalue;

import java.sql.Date;

public class ReferenceExample {

    public static void addCentury(Date recent, Date old) {
        old.setDate(100);
        recent = old;

        System.out.println(recent);
    }

    public static void main(String[] args) {
        Date oldDate = new Date(1, 13, 1900);
        Date recentDate = new Date(1, 13, 1900);
        addCentury(recentDate, oldDate);
        System.out.println(recentDate);
        System.out.println(oldDate);

    }

}
