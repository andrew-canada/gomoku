package com.andrew.ap.java.classes.binding;

public class GFG2 {

    // Static nested inner class
    // Class 1
    public class superclass {

        // Method of inner class 1
        void print() {

            // Print statement
            System.out.println(
                    "print in superclass is called");
        }
    }

    // Static nested inner class
    // Class 2
    public class subclass extends superclass {

        // Method of inner class 2
        @Override
        void print() {

            // Print statement
            System.out.println(
                    "print in subclass is called");
        }
    }

    // Method inside main class
    public static void main(String[] args) {

        // Creating object of inner class 1
        // with reference to constructor of super class
        superclass A = (new GFG2()).new superclass();

        // Creating object of inner class 1
        // with reference to constructor of sub class
        superclass B = (new GFG2()).new subclass();

        // Calling print() method over above objects
        A.print();
        B.print();
    }
}
