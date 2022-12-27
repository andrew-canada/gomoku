package com.andrew.annotations.example;

import com.andrew.annotations.model.Engineer;
import com.andrew.annotations.model.Person;
import com.andrew.annotations.model.Student;

public class Main {

	@SuppressWarnings({ "deprecation", "removal" })
	public static void main(String[] args) {
		Person john = new Person("john", 48);
		Person joe = new Engineer("joe", 51);
		Student bob = new Student("bob", 29);
		Student nullStudent = null;
		Engineer jack = new Engineer("jack", 10);

		System.out.println(john.getInfo());
		System.out.println(joe.getInfo());
		System.out.println(joe.getInfoV2());
		System.out.println(nullStudent);
		// System.out.println(nullStudent.getAge());
		bob.printName();
		jack.printSum(1, 3.5);
		jack.printSum(1, 3);

		Person defaultPerson = new Engineer();
		System.out.println(defaultPerson);
	}

}
