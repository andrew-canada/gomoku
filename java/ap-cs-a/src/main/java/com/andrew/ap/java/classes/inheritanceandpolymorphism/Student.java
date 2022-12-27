package com.andrew.ap.java.classes.inheritanceandpolymorphism;

public class Student extends Person {
    private double grade;

    public Student(String name, int age, double grade) {
        super(name, age);
        this.grade = grade;
    }

    @Override
    public void greet() {
        System.out.println("I am a student");
        super.greet();
    }

    public double getGrade() {
        return this.grade;
    }

    @Override
    public String toString() {
        return "name: " + super.getName() + ", age: " + super.getAge() + ", grade: " + this.grade;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        return (other instanceof Student p
                && (super.getName().equals(p.getName()) && super.getAge() == p.getAge() && grade == p.grade));
    }
}
