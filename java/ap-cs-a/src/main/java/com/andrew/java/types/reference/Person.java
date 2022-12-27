package com.andrew.java.types.reference;

public class Person extends Animal {
	public Person(String name, byte age) {
		super();
		this.name = name;
		this.age = age;
	}

	public Person() {

	}

	private String name;
	private byte age;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public byte getAge() {
		return age;
	}

	public void setAge(byte age) {
		this.age = age;
	}
}
