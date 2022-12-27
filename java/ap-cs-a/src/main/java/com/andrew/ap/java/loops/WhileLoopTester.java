package com.andrew.ap.java.loops;

public class WhileLoopTester {

    public static void main(String[] args) {
        double amount = 200;
        int numYears = 0;

        while (amount <= 1000) {
            amount *= 1.1;
            numYears += 1;
        }

        System.out.println(numYears);

        int multipleNum = 1;
        int sum = 0;
        while (multipleNum <= 10) {
            sum += 4 * multipleNum;
            multipleNum += 1;
        }

        System.out.println(sum);

        int number = 1234;
        int digitSum = 0;
        while (number > 0) {
            digitSum += number % 10;
            number /= 10;
        }

        System.out.println(digitSum);
    }

}
