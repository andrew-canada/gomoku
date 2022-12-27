package com.andrew.ap.java.arraylist;

public class Student {

    private String name;
    private String id;
    private int age;

    public Student(String name, String id, int age) {
        this.name = name;
        this.id = id;
        this.age = age;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Student [name=" + name + ", id=" + id + ", age=" + age + "]";
    }
}
