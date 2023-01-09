package com.andrew.java.algo.string;

public class PalindromeMaker {
    private PalindromeMaker() {
    }

    private static String reverse(String str) {
        String reversedStr = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            reversedStr += str.substring(i, i + 1);
        }
        return reversedStr;
    }

    private static String reverseWithStringBuilder(String str) {
        StringBuilder sb = new StringBuilder();
        for (int i = str.length() - 1; i >= 0; i--) {
            sb.append(str.substring(i, i + 1));
        }
        return sb.toString();
    }

    public static String changeToPalindrome(String str) {
        String palindromeStr = "";
        int strLength = str.length();
        palindromeStr += str.substring(0, (strLength + 1) / 2);
        palindromeStr += reverse(str.substring(0, strLength / 2));
        return palindromeStr;
    }
}
