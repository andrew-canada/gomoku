package com.andrew.java.types.reference;

public class PersonWithToString {
	public PersonWithToString(String name, byte age) {
		super();
		this.name = name;
		this.age = age;
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

	@Override
	public String toString() {
		return "PersonWithToString [name=" + name + ", age=" + age + "]";
	}
}
