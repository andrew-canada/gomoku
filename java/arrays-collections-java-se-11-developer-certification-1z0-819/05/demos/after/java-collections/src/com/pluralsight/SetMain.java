package com.pluralsight;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class SetMain {
    public static void main(String... args) {
        Set<Integer> primeNumbers1 = new HashSet<>();
        Set<Integer> primeNumbers2 = new TreeSet<>();

        primeNumbers1.add(71);
        primeNumbers1.add(61);
        primeNumbers1.add(41);
        primeNumbers1.add(1);

        primeNumbers2.add(71);
        primeNumbers2.add(61);
        primeNumbers2.add(41);
        primeNumbers2.add(1);

        primeNumbers1.forEach(System.out::println);
        System.out.println("");
        primeNumbers2.forEach(System.out::println);

        System.out.println(primeNumbers1.add(5));
        System.out.println(primeNumbers1.add(5));

        primeNumbers1.remove(5);
        System.out.println(primeNumbers1.isEmpty());
        System.out.println(primeNumbers1.size());

    }

}
