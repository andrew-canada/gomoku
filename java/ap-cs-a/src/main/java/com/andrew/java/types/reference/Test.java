package com.andrew.java.types.reference;

public class Test {

	public static void main(String[] args) {
		Person andrew = new Person("andrew", (byte) 1);
		// Person michael = new Person();
		System.out.println(andrew.getFur());
		andrew.setFur("hard hair");
		System.out.println(andrew.getFur());
		Person p1 = (Person) Animal.getInstance("person");

	}

}
