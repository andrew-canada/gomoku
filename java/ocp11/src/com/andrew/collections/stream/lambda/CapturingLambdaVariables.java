package com.andrew.collections.stream.lambda;

import java.util.List;

import com.andrew.model.MarkFilter;
import com.andrew.model.Student;
import com.andrew.model.util.StudentSample;

/*
 * captured variables must be effectively final
 * avoid side effects (change state of variables)
 * this and super have same meaning as in surrounding code
 */

public class CapturingLambdaVariables {

	public static void printStudents(List<Student> studentList, MarkFilter<Student> mf) {

		for (Student s : studentList) {
			if (mf.accept(s)) {
				System.out.println(s.getName());
			} else {
				System.out.println("no");
			}
		}
	}

	public static void main(String[] args) {

		double passingMark = 59.9;

		List<Student> studentList = StudentSample.getStudentList();

		MarkFilter<Student> mf = student -> student.getGrade() >= passingMark;

		printStudents(studentList, mf);

		System.out.println("-------------");

		// anyMatch must receive a PREDICATE
		// mf is equal to "student -> student.getGrade() >= passingMark" but it isn't a
		// predicate
		System.out.println(studentList.stream().anyMatch(student -> student.getGrade() >= passingMark));
	}

}
