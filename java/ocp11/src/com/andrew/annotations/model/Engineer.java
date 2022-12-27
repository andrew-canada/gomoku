package com.andrew.annotations.model;

import com.andrew.annotations.Version;

// @formatter:off

/**
 * abc
 * @author andrew 
 * @see <a href="https://docs.oracle.com/en/java/">Java Dcoumentation</a>
 */

//@formatter:on
@Deprecated
@Version(value = 1, author = "andrew")
@Version(value = 1, author = "joe")
public class Engineer extends Person {

	@Deprecated
	@Version(value = 1, author = "a")
	@Version(value = 1, author = "b")
	public Engineer() {
	}

	@Version(value = 1, author = "a")
	public Engineer(String name, int age) {
		super(name, age);
	}

	@Version(value = 1, author = "b")
	public void printSum(int num1, int num2) {
		System.out.println(num1 + num2);
	}

	public void printSum(int num1, double num2) {
		System.out.println(num1 + num2);
	}

	@Override
	// can't override final methods
	public String getInfo() {
		return String.format("engineer [%d] %s", this.age, this.name);
	}

	@Override
	public String getInfoV2() {
		return String.format("V2: engineer [%d] %s", this.age, this.name);
	}

}
