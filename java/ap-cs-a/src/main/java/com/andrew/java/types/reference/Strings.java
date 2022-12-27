package com.andrew.java.types.reference;

public class Strings {

	public static void main(String[] args) {

		// strings are reference types, but they are instantiated by the string literal
		// only
		// strings do not need new operator because they are often used
		String message = "Hello World";
		System.out.println(message);

		// concatenate strings with + operator
		String message2 = "  Hello World" + "!!  ";

		// string reference types has many members
		System.out.println(message2.endsWith("!!"));
		System.out.println(message2.startsWith("!!"));
		System.out.println(message2.length());

		// member indexOf tells the index (starts at 0) of the first occurrence of the
		// specified character
		System.out.println(message2.indexOf("l"));

		// -1 means the character doesn't exist
		System.out.println(message2.indexOf("8"));

		// replaces all instances of the specified character
		// strings are immutable. the can't be changed
		// any methods that modify a string always return a new string object
		System.out.println(message2.replace("!", "?"));
		System.out.println(message2);

		System.out.println(message2.toUpperCase());
		System.out.println(message2);

		// removes unnecessary spaces
		System.out.println(message2.trim());
		System.out.println(message2);
	}

}
