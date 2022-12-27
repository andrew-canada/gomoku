package com.andrew.ap.java.classes;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CarApp {

    public static void main(String[] args) {

        int a = 1;
        double b = 2.0;
        List<Object> nums = new ArrayList<>();
        nums.add(a);
        nums.add(b);
        for (int val : nums) {
            System.out.println(val);
        }
        System.out.println(2 / 0.0);
        System.out.println(0.0 / 0.0);
        System.out.println(Integer.MAX_VALUE);
        System.out.println(Integer.MIN_VALUE);
        Car blueCar = new Car("blueCar", "blue");
        Car redCar = new Car("redCar", "red");
        Car blueCarCopy = blueCar;
        Car defaultCar = new Car();
        Car nullCar = null;

        List<Car> carList = new ArrayList<>(Arrays.asList(blueCar, redCar, blueCarCopy));

        carList.stream().forEach(System.out::println);

        blueCarCopy.setColor("orange");
        redCar.setColor(null);
        carList.stream().forEach(System.out::println);

        blueCar.makeSound();
        blueCar.sum(1, 1);
        blueCar.sum(1, 1, 1);

        System.out.println(defaultCar);
        System.out.println(nullCar);
        nullCar = new Car("nullCar", "colorless");
        System.out.println(nullCar);

        blueCar.move();
        redCar.move(15);
        nullCar.move("right");
        blueCarCopy.move(15, "right");

        System.out.println(blueCar.calculateDistance(2, 21.3));

        System.out.println(blueCar);
        System.out.println(redCar);
        redCar.changeColor(blueCar);

        System.out.println(blueCar);
        System.out.println(redCar);
    }

}
