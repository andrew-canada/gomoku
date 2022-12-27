package com.exceptions.m3;

public class TryWithResourcesReverseClose {

	public static void main(String[] args) {

		try (var one = new MyResource("One"); var two = new MyResource("Two")) {
			System.out.println("");
			try {
				test();
			} catch (Throwable ta) {
				System.out.println(ta.getMessage());
			}
			System.out.println("aa");
			throw new RuntimeException("from main()");
		}

	}

	public static void test() {
		throw new RuntimeException("from test()");
	}
}
