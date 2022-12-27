package com.andrew.java.algo.array;

import java.util.Objects;

public class DebugDuck implements Comparable<DebugDuck> {

    private String name;
    private int age;

    public DebugDuck(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "DebugDuck [name=" + name + ", age=" + age + "]";
    }

    @Override
    public int hashCode() {
        return Objects.hash(age, name);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        DebugDuck other = (DebugDuck) obj;
        return age == other.age && Objects.equals(name, other.name);
    }

    @Override
    public int compareTo(DebugDuck o) {
        return this.age - o.age;
    }
}
