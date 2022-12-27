/*
 * This code is part of the course "Working with Streams and Lambda Expressions in Java (Java SE 11 Developer Certification 1Z0-819)" for Pluralsight.
 *
 * Copyright (C) 2021 by Jesper de Jong (jesper@jdj-it.com).
 */
package com.andrew.exercises.model;

//@formatter:off
public enum Category {
	FOOD("FOOD"), 
	UTENSILS("utensils"), 
	CLEANING("cleaning"), 
	OFFICE("office");

	//@formatter:on
	private String value;

	Category(String string) {
		this.value = string;
	}

	@Override
	public String toString() {
		return value;
	}

}
