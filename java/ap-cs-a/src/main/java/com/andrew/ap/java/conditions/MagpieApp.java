package com.andrew.ap.java.conditions;

import java.util.Scanner;

public class MagpieApp {

    public static void main(String[] args) {
        System.out.println(Magpie.GREETING_MSG);
        Scanner scanner = new Scanner(System.in);
        String msg = scanner.nextLine();

        while (!msg.equalsIgnoreCase("bye!")) {
            System.out.println(Magpie.getResponse(msg));
            msg = scanner.nextLine();
        }

        scanner.close();

        System.out.println(Magpie.getFarewell());

    }

}
