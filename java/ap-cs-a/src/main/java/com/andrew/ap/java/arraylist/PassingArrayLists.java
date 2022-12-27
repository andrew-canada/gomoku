package com.andrew.ap.java.arraylist;

import java.util.ArrayList;

public class PassingArrayLists {

    public static void main(String[] args) {
        ArrayList<String> names = new ArrayList<>();
        names.add(new String("abc"));
        updateListBad(names);
        System.out.println(names);

        ArrayList<String> newNames = new ArrayList<>();
        newNames.add("abc");
        updateListBad1(newNames);
        System.out.println(newNames);

        ArrayList<String> newNames2 = new ArrayList<>();
        newNames2.add("abc");
        String test = newNames2.get(0);
        updateListGood(newNames2);
        System.out.println(newNames2);

        System.out.println(getList());

    }

    public static ArrayList updateListBad(ArrayList a) {
        a.add(true);
        return a;
    }

    public static ArrayList updateListGood(ArrayList<String> a) {
        // a.add(true);
        a.add("true");
        return a;
    }

    public static ArrayList<String> updateListBad1(ArrayList a) {
        a.add(true);
        return a;
    }

    public static ArrayList<String> getList() {
//        ArrayList<Boolean> newList = new ArrayList<>();
//        return newList;
        ArrayList<String> strList = new ArrayList<>();
        return strList;
    }

}
