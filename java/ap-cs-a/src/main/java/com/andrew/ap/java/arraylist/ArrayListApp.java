package com.andrew.ap.java.arraylist;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ArrayListApp {

    public static void main(String[] args) {
        List<Integer> temperatures = new ArrayList<>(Arrays.asList(1, 2, 3));
        int temperature1 = temperatures.remove(0);
        System.out.println(temperature1);
        temperatures.stream().forEach(System.out::print);

    }

}
