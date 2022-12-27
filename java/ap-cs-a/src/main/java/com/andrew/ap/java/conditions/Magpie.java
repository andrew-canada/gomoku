package com.andrew.ap.java.conditions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Magpie {

    private Magpie() {
    }

    private static final List<String> RANDOM_RESPONSES = new ArrayList<>(
            Arrays.asList("It is sunny today", "Ice cream is good", "Do you want a sandwich?"));

    public static final String GREETING_MSG = "Hello! What's on your mind today?";

    public static String getResponse(String msg) {
        String response;

        if (msg.indexOf("want") != -1) {
            response = "Are you sure you want ";
            String item = msg.substring(msg.indexOf("want") + 5);
            response += item;
            response += "?";
        } else if (msg.indexOf("know") != -1 && msg.indexOf("you") != -1) {
            response = "Now you do!";
        } else if (msg.indexOf("yes") != -1) {
            response = "You eat too much!";
        } else if (msg.indexOf("no") != -1) {
            response = "Why not?";
        } else {
            int num = (int) (Math.random() * RANDOM_RESPONSES.size());
            response = RANDOM_RESPONSES.get(num);
        }

        return response;
    }

    public static String getFarewell() {
        return "See you later!";
    }
}
