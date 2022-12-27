package com.andrew.ap.java.loops;

public class EquivalentLoopTest {

    public static void main(String[] args) {
        for (int i = 0; i < 50; i++) {
            if (i % 5 == 0) {
                System.out.println(i);
            }
        }

        for (int i = 0; i < 50; i += 5) {
            System.out.println(i);
        }
    }

}
