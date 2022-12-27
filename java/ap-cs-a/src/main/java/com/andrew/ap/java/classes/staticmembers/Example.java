package com.andrew.ap.java.classes.staticmembers;

public class Example {
    public static int goal = 125;
    private int current;

    public Example(int c) {
        // Example.goal = c; // bad -> resets goal after each Example instantiation
        this.current = c;
    }

    public static void resetGoal(int g) {
        Example.goal = g;
        // this.current = g;
    }

    public void resetGoal2(int g) {
        Example.goal = g;
        // this.current = g;
    }

    @Override
    public String toString() {
        return "Example [current=" + current + "]";
    }
}
