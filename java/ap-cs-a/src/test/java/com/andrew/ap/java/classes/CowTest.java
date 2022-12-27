package com.andrew.ap.java.classes;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class CowTest {

    Cow bessie;

    @BeforeEach
    void setUp() throws Exception {
        bessie = new Cow("holstein", "moo");
    }

    @Test
    void testGetType() {
        Assertions.assertEquals("holstein", bessie.getType());
    }

    @Test
    void testGetSound() {
        Assertions.assertEquals("moo", bessie.getSound());
    }

    @Test
    void testMilkCow() {
        bessie.milkCow();
        Assertions.assertEquals(1, bessie.getNumMilkings());
        bessie.milkCow();
        bessie.milkCow();
        Assertions.assertEquals(3, bessie.getNumMilkings());
    }

}
