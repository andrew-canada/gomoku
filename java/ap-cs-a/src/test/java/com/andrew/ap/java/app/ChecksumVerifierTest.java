package com.andrew.ap.java.app;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class ChecksumVerifierTest {

    @Test
    void testCheckIfValid() {
        Assertions.assertEquals(false, ChecksumVerifier.checkIfValid(111));
        Assertions.assertEquals(false, ChecksumVerifier.checkIfValid(11111));
        Assertions.assertEquals(false, ChecksumVerifier.checkIfValid(1111));
        Assertions.assertEquals(true, ChecksumVerifier.checkIfValid(1670));
    }

}
