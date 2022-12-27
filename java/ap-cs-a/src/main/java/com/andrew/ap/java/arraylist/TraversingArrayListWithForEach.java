package com.andrew.ap.java.arraylist;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TraversingArrayListWithForEach {

    public static void main(String[] args) {
        List<Student> studentList = new ArrayList<>(
                Arrays.asList(new Student("s1", "1", 1), new Student("s2", "2", 2), new Student("s3", "3", 3)));

        for (Student s : studentList) {
            s.setName("new name");
            System.out.println(s);
        }

        System.out.println(studentList);

        List<Double> doubleList = new ArrayList<>(Arrays.asList(1.0, 2.0, 3.0));

        int count = 0;
        for (Double d : doubleList) {
            d += 1;
            System.out.println(d);
            doubleList.set(count++, d);
        }
        System.out.println(doubleList);
    }

}
