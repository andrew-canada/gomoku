package com.andrew.ap.java.classes;

import java.util.ArrayList;
import java.util.List;

public class StudentTest {

	public static void main(String[] args) {
		Student s1 = new Student("joe", 100);
		SecondaryStudent ss1 = new SecondaryStudent("john", 100, 40);

		List<Student> studentList = new ArrayList<>();
		studentList.add(s1);
		studentList.add(ss1);
		for (Student s : studentList) {
			System.out.println(s.getScore());
		}

		System.out.println(s1);
		System.out.println(ss1);

	}

}
