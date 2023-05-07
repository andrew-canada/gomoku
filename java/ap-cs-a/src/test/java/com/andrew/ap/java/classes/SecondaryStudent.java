package com.andrew.ap.java.classes;

public class SecondaryStudent extends Student {
	private double hours;

	public SecondaryStudent(String name, int grade, double hours) {
		super(name, grade);
		this.hours = hours;
	}

	@Override
	public double getScore() {
		return super.getScore() + hours;
	}
}
