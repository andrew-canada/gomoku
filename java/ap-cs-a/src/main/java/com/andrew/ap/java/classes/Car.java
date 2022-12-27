package com.andrew.ap.java.classes;

public class Car {

    private String name;
    private String color;

    public Car(String color) {
        this.color = color;
    }

    public Car() {
    }

    public Car(String name, String color) {
        this.name = name;
        this.color = color;
    }

    public void changeColor(Car otherCar) {
        this.color = otherCar.color;
        otherCar.color = "a";
    }

    public void makeSound() {
        System.out.println("aaaaaaaa");
    }

    public void sum(int int1, int int2) {
        System.out.println(int1 + int2);
    }

    public void sum(int int1, int int2, int int3) {
        System.out.println(int1 + int2 + int3);
    }

    public void move() {
        System.out.println("The car moved 3 forward");
    }

    public void move(int distance) {
        System.out.println("The car moved " + distance + " forward");
    }

    public void move(String direction) {
        System.out.println("The car moved 3 " + direction);
    }

    public void move(int distance, String direction) {
        System.out.println("The car moved " + distance + " " + direction);
    }

    public double calculateDistance(double start, double end) {
        return end - start;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Car [name=" + name + ", color=" + color + "]";
    }

}
