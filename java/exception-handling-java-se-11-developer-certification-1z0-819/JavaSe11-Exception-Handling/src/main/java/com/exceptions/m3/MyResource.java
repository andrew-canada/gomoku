package com.exceptions.m3;

public class MyResource implements AutoCloseable {

	String name;

	public MyResource(String name) {
		this.name = name;
	}

	@Override
	public void close() {
		System.out.println("Closing resource #: " + name);
	}
}
