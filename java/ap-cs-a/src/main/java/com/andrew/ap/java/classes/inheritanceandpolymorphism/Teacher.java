package com.andrew.ap.java.classes.inheritanceandpolymorphism;

public class Teacher extends Person {
    private int numTeachingYears;

    public Teacher(String name, int age, int numTeachingYears) {
        super(name, age);
        this.numTeachingYears = numTeachingYears;
    }

    @Override
    public void greet() {
        System.out.println("I am a teacher");
        super.greet();
    }

    public double getNumTeachingYears() {
        return this.numTeachingYears;
    }
}
