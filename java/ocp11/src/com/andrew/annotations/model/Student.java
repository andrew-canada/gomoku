/**
 * 
 */
package com.andrew.annotations.model;

/**
 * @author peng
 *
 */
public class Student extends Person {

	public Student() {
	}

	/**
	 * @param name
	 * @param age
	 */
	public Student(String name, int age) {
		super(name, age);
	}

	@Deprecated
	public void printName() {
		System.out.println(name);
	}

}
