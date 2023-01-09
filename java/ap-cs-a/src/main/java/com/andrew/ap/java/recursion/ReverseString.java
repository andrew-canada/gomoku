package com.andrew.ap.java.recursion;

public class ReverseString {
    private ReverseString() {
    }

    public static String getReverse(String word) {
        String result = "";
        if (word.length() == 0) {
            return word;
        } else {
            result = getReverse(word.substring(1));
            result += word.substring(0, 1);
        }
        return result;
    }
}
