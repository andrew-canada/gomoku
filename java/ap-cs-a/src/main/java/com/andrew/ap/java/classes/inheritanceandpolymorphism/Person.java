package com.andrew.ap.java.classes.inheritanceandpolymorphism;

public class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void greet() {
        System.out.println("I am a person");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "name: " + name + ", age: " + age;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        return (other instanceof Person p && (this.name.equals(p.name) && this.age == p.age));
    }
}
