package com.andrew.java.types.reference;

public abstract class Animal {

	private String fur;

	public static Animal getInstance(String type) {
		if (type.equalsIgnoreCase("person")) {
			return new Person();
		} else {
			return null;
		}
	}

	public String getFur() {
		return fur;
	}

	public void setFur(String fur) {
		this.fur = fur;
	}

}
