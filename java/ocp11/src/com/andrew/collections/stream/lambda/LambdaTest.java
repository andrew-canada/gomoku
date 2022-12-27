package com.andrew.collections.stream.lambda;

import java.util.ArrayList;
import java.util.List;

import com.andrew.model.Student;

/*
 * lambda is anonymous method
 * lambda implements functional interface (single abstract method)
 * 3 parts:
 *  	1. parameters
 * 		2. arrow
 * 		3. body
 */

public class LambdaTest {

	public static void main(String[] args) {
		List<Student> students = new ArrayList<>();

		Student s1 = new Student("a", 1);
		Student s2 = new Student("b", 2);
		Student s3 = new Student("c", 3);
		Student s4 = new Student("d", 4);
		Student s5 = new Student("e", 5);
		Student s6 = new Student("f", 6);

		students.add(s3);
		students.add(s1);
		students.add(s4);
		students.add(s2);
		students.add(s5);
		students.add(s6);

		students.stream().forEach(System.out::println);

		students.sort((st1, st2) -> st1.getId() - st2.getId());

		System.out.println("--------------------");

		students.stream().forEach(System.out::println);

	}

}
