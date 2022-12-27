package com.andrew.ap.java.classes.staticmembers;

public class StaticMemberTester {

    public static void main(String[] args) {
        Example e = new Example(0);
        Example e1 = new Example(0);
        Example e2 = new Example(0);

        System.out.println(e);
        System.out.println(Example.goal);
        Example.goal += 1;
        System.out.println(e1);
        System.out.println(Example.goal);
        Example.goal += 1;
        System.out.println(e2);
        System.out.println(Example.goal);
    }

}
