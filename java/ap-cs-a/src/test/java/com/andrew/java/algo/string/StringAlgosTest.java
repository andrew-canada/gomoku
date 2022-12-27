package com.andrew.java.algo.string;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class StringAlgosTest {

    @Test
    void testFindSubstring() {
        Assertions.assertEquals(true, StringAlgos.findSubstring("sunflower", "r"));
        Assertions.assertEquals(true, StringAlgos.findSubstring("sunflower", "sun"));
        Assertions.assertEquals(false, StringAlgos.findSubstring("sunflower", "a"));
        Assertions.assertEquals(false, StringAlgos.findSubstring(null, "r"));
        Assertions.assertEquals(false, StringAlgos.findSubstring("r", null));
        Assertions.assertEquals(false, StringAlgos.findSubstring(null, null));
    }

    @Test
    void testCountVowels() {
        Assertions.assertEquals(5, StringAlgos.countVowels("aeioux"));
        Assertions.assertEquals(0, StringAlgos.countVowels("pppppp"));
        Assertions.assertEquals(1, StringAlgos.countVowels("wxy am"));
        Assertions.assertEquals(1, StringAlgos.countVowels("ttttto"));
        Exception e = Assertions.assertThrows(NullPointerException.class, () -> StringAlgos.countVowels(null));
        Assertions.assertEquals("input is null, expected nonnull string", e.getMessage());
    }

    @Test
    void testReverseString() {
        Assertions.assertEquals("edcba", StringAlgos.reverseString("abcde"));
        Assertions.assertEquals("om on", StringAlgos.reverseString("no mo"));
        Assertions.assertNotEquals("a", StringAlgos.reverseString("no mo"));

        Exception e = Assertions.assertThrows(NullPointerException.class, () -> StringAlgos.reverseString(null));
        Assertions.assertEquals("input is null, expected nonnull string", e.getMessage());
    }

}
