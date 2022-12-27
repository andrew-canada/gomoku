package com.pluralsight;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class MapMain {
    public static void main(String... args) {
        HashMap countries = new HashMap();
        HashMap<Integer, String> countries2 = new HashMap<>();
        Map languages = new HashMap();
        Map<String, String> languages2 = new HashMap<>();

        countries2.put(840, "USA");
        countries2.put(484, "MEX");
        countries2.put(124, "CAN");

        System.out.println(countries2.get(840));

        countries2.remove(840);

        countries2.keySet();

        countries2.put(124, "CAN");
        countries2.put(124, "ABC");

        countries2.values();

        countries2.containsKey(840);
        countries2.containsValue("USA");

        countries2.put(-1, null);
        countries2.put(null, null);

        TreeMap<Integer, String> planets = new TreeMap<>();
        Map<String, String> englishSpanish = new TreeMap<>();

        planets.put(3, "Earth");
        planets.put(2, "Venus");
        planets.put(4, "Mars");

        planets.put(Integer.valueOf(3), "Earth");

        englishSpanish.put("dog", "perro");
        englishSpanish.put("cat", "gato");
        englishSpanish.put("fish", "pez");

        System.out.println(planets.keySet().toString());
        System.out.println(englishSpanish.keySet().toString());

        planets.put(20, null);
        planets.put(null, null);
    }

}
