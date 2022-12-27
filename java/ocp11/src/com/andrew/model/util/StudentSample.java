package com.andrew.model.util;

import java.util.ArrayList;
import java.util.List;

import com.andrew.model.Student;

public class StudentSample {

	public static List<Student> getStudentList() {
		Student s1 = new Student("a", 1, 99.1);
		Student s2 = new Student("b", 2, 22);
		Student s3 = new Student("c", 3, -88);
		Student s4 = new Student("d", 4, 60);
		Student s5 = new Student("e", 5, 60.1);

		List<Student> studentList = new ArrayList<>();

		studentList.add(s5);
		studentList.add(s3);
		studentList.add(s4);
		studentList.add(s1);
		studentList.add(s2);

		return studentList;

	}

}
