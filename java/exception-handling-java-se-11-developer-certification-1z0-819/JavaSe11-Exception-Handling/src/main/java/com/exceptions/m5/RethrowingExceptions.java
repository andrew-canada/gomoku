package com.exceptions.m5;

import java.io.IOException;

public class RethrowingExceptions {

	static void throwException() throws IOException {
		System.out.println("throw exception");
		throw new IOException();
	}

	static void rethrowException() throws IOException {
		System.out.println("rethrow exception");
		throwException();
	}

	public static void main(String[] args) {
		try {
			rethrowException();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
