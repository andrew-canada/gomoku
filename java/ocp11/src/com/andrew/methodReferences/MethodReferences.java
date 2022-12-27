package com.andrew.methodReferences;

import java.util.List;

import com.andrew.model.Student;
import com.andrew.model.StudentFactory;
import com.andrew.model.util.StudentSample;

/*
 * method references can be used instead lambda when there is pre-existing method
 * method references can be used with:
 * 		1 static method - ClassName::methodName
 * 		2 
 * 			- instance of specific object - objectRef::methodName
 * 			- not specific object (same as static) - ClassName::methodName
 * 		3 constructor - ClassName::new
 */

public class MethodReferences {

	public static boolean isPassingMark(Student s) {
		return s.getGrade() >= 60;
	}

	public static boolean isFailingMark(Student s) {
		return s.getGrade() < 60;
	}

	public static void main(String[] args) {

		List<Student> studentList = StudentSample.getStudentList();

		studentList.forEach(System.out::println);

		System.out.println("---");

		List<Student> students = studentList.stream().filter(MethodReferences::isPassingMark).toList();
		students.forEach(System.out::println);

		System.out.println("---");

		studentList.stream().filter(MethodReferences::isPassingMark).forEach(System.out::println);

		System.out.println("--removeIf() == filter--");

		// static methods
		// name of class :: method name
		studentList.removeIf(MethodReferences::isPassingMark);

		// instance method with specific object
		// before double colon->reference to object
		// println method of particular printstream object referred to by system.out
		studentList.forEach(System.out::println);

		// instance method without specific object
		studentList.stream().map(Student::getName).forEach(System.out::println);

		// constructor methods
		// often used in factory design pattern
		StudentFactory sf = Student::new;
		Student s1 = sf.makeStudent("s1", 111);
		System.out.println(s1);

	}

}
