package com.andrew.java.algo.string;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class PalindromeMakerTest {

    @Test
    void testChangeToPalindrome() {
        Assertions.assertEquals("abba", PalindromeMaker.changeToPalindrome("abcd"));
        Assertions.assertEquals("abcba", PalindromeMaker.changeToPalindrome("abcde"));
    }

}
