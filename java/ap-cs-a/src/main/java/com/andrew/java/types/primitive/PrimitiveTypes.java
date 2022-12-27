package com.andrew.java.types.primitive;

public class PrimitiveTypes {

	public static void main(String[] args) {
		byte weight = 56;
		byte age = 67;
		
		// java sees numberOfClouds as an int, so add L to tell java it is a long
		long numberOfClouds = 6_666_666_666L;
		
		// java sees volume as a double, so add F to tell java it is a float
		float volume = 55.55F;
		
		System.out.println(weight);
		
		//surround single characters with single quotes, string with double quotes
		char letter = 'B';
		System.out.println(letter);
		
		// char only contain 1 character. below is wrong
		//char grade = 'AB';
		
		boolean isRight;
		//System.out.println("is there a default value for isRight: " + isRight);
		
		boolean isCompatable = false;
		System.out.println(isCompatable);
	}

}
