package com.andrew.java.algo.array;

import org.apache.commons.lang3.tuple.ImmutablePair;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class MaxAndMinFinderTest {

	MaxAndMinFinder mamf;
	double doubleValues[] = { 1, 3.4, -1 };

	@BeforeEach
	void setUp() {
		mamf = new MaxAndMinFinder();
	}

	@Test
	void testFindMax() {
		Assertions.assertEquals(3.4, mamf.findMax(doubleValues));
	}

	@Test
	void testFindMaxNullValue() {
		Exception e = Assertions.assertThrows(NullPointerException.class, () -> mamf.findMax(null));
		Assertions.assertEquals("input is null, expected double arr.", e.getMessage());
	}

	@Test
	void testFindMaxWithStream() {
		Assertions.assertEquals(3.4, mamf.findMaxWithStream(doubleValues));
	}

	@Test
	@DisplayName("Find min value from array")
	void testFindMin() {
		Assertions.assertEquals(-1, mamf.findMin(doubleValues));

	}

	@Test
	@DisplayName("Find Max value and index from array")
	void testFindMaxValAndIndex() {
		Assertions.assertEquals(new ImmutablePair<Integer, Double>(1, 3.4), mamf.findMaxValAndIndex(doubleValues));

	}

}
