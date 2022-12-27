package com.andrew.annotations.model;

import com.andrew.annotations.Version;

@Version(value = 1, author = "Joe", environments = { "development", "testing" })
public class Person {

	protected String name;
	protected int age;
	boolean isAdult;

	public Person() {
	}

	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public boolean isAdult() {
		return isAdult;
	}

	public void setAdult(boolean isAdult) {
		this.isAdult = isAdult;
	}

	@Deprecated(since = "1.0", forRemoval = true)
	public String getInfo() {
		return String.format("person [%d] %s", this.age, this.name);
	}

	public String getInfoV2() {
		return String.format("V2: person [%d] %s", this.age, this.name);
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + ", isAdult=" + isAdult + "]";
	}

}
