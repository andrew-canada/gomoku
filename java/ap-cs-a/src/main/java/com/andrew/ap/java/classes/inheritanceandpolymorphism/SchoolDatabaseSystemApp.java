package com.andrew.ap.java.classes.inheritanceandpolymorphism;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SchoolDatabaseSystemApp {

    public static void main(String[] args) {
        System.out.println("er".substring(2));
        System.out.println("er".substring(3));

        Person student1 = new Student("s1", 12, 100);
        Person student2 = new Student("s2", 13, 100);
        Person teacher1 = new Teacher("t1", 52, 30);

        List<Person> members = new ArrayList<>(Arrays.asList(student1, student2, teacher1));
        SchoolDatabaseSystem tdsbSystem = new SchoolDatabaseSystem(members);

        System.out.println(tdsbSystem.getMembers());

        student1.greet();
        System.out.println();
        teacher1.greet();
        System.out.println();

        // double grade = student1.getGrade();
        double grade = ((Student) student1).getGrade();
        System.out.println(grade);

        Person teacher2 = new Teacher("t1", 52, 30);
        Person teacher3 = new Teacher("t1", 52, 31);
        System.out.println(teacher1.equals(teacher2));
        System.out.println(teacher1.equals(teacher3));

        // student2 = new Student("s2", 13, 100);
        Person student3 = new Student("s2", 13, 100);
        Person student4 = new Student("s2", 13, 101);
        System.out.println(student2.equals(student3));
        System.out.println(student2.equals(student4));

    }

}
