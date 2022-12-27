package com.andrew.java.algo.string;

import java.util.Optional;

public class StringAlgos {

    private StringAlgos() {
    }

    public static boolean findSubstring(String originalWord, String substring) {
        if (originalWord == null || substring == null) {
            return false;
        }

        int substringLength = substring.length();
        boolean isFound = false;

        for (int i = 0; i <= originalWord.length() - substringLength; i++) {
            if (originalWord.substring(i, i + substringLength).equals(substring)) {
                isFound = true;
                break;
            }
        }
        return isFound;
    }

    public static int countVowels(String input) throws NullPointerException {
        if (Optional.ofNullable(input).isEmpty()) {
            throw new NullPointerException("input is null, expected nonnull string");
        }
        int numVowels = 0;
        for (int i = 0; i < input.length(); i++) {
            String currentChar = input.substring(i, i + 1);
            if (currentChar.equalsIgnoreCase("a") || currentChar.equalsIgnoreCase("e")
                    || currentChar.equalsIgnoreCase("i") || currentChar.equalsIgnoreCase("o")
                    || currentChar.equalsIgnoreCase("u")) {
                numVowels += 1;
            }
        }
        return numVowels;
    }

    public static String reverseString(String input) throws NullPointerException {
        if (Optional.ofNullable(input).isEmpty()) {
            throw new NullPointerException("input is null, expected nonnull string");
        }

        String reversedString = "";
        for (int i = 0; i < input.length(); i++) {
            reversedString = input.substring(i, i + 1) + reversedString;
        }
        return reversedString;
    }

}
