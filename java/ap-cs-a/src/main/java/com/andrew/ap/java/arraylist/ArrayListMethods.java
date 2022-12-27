package com.andrew.ap.java.arraylist;

import java.util.ArrayList;
import java.util.List;

public class ArrayListMethods {

    public static void main(String[] args) {
        List<String> names = new ArrayList<>();
        List<String> names2 = new ArrayList<>(5);
        System.out.println(names.size());
        System.out.println(names2.size());
        names.add("a");
        names2.add("a");

        names.add(0, "b");
        names2.add(1, "b");
        // names2.add(10, "c");
        System.out.println(names);
        System.out.println(names2);

        // System.out.println(names.get(10));
        System.out.println(names.get(0));

        names.set(0, "b");
        // names.set(1, "b");
        System.out.println(names);

        names.remove(0);
        // names.remove(10);
        System.out.println(names);

    }

}
