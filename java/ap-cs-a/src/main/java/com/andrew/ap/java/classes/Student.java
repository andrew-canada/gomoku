package com.andrew.ap.java.classes;

public class Student {
	private String name;
	private int grade;

	public Student(String name, int grade) {
		this.name = name;
		this.grade = grade;
	}

	public String getName() {
		return name;
	}

	public void updateGrade(int newGrade) {
		this.grade = newGrade;
	}

	public int getGrade() {
		return grade;
	}

	public double getScore() {
		return grade * 2;
	}

	@Override
	public String toString() {
		return "Student [name=" + name + ", grade=" + grade + "]";
	}
}
