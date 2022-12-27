package com.andrew.ap.java.arraylist;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TraversingArrayLists {

    public static void main(String[] args) {
        List<Integer> grades = new ArrayList<>(Arrays.asList(5, 4, 4, 3));
        for (int i = 0; i < grades.size(); i++) {
            if (grades.get(i) == 4) {
                // bad
                grades.remove(i);
                i -= 1;
            }
        }
        System.out.println(grades);

        grades.add(1, 4);
        grades.add(1, 4);
        for (int i = grades.size() - 1; i >= 0; i--) {
            if (grades.get(i) == 4) {
                // good
                grades.remove(i);
            }
        }
        System.out.println(grades);

        grades.add(1, 4);
        grades.add(1, 4);
        int counter = 0;
        for (int grade : grades) {
            if (grade == 4) {
                // can't remove elements using for-each (like stream)
                grades.remove(counter);
            }
            counter += 1;
        }

    }

}
