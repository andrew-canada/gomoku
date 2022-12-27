package com.andrew.java.algo.array;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

class AvgFinderTest {

	AvgFinder af;
	DebugDuck[] duckArr = { new DebugDuck("d1", 1), new DebugDuck("d2", 3), new DebugDuck("d3", 2) };

	@BeforeEach
	void setup() {
		af = new AvgFinder();
	}

	@Test
	void testForLoopAvg() {
		Assertions.assertEquals(2, af.forLoopAvg(duckArr));
	}

	@Test
	@DisplayName("average from DebugDuck array with foreach")
	void testForEachLoopAvg() {
		Assertions.assertEquals(2, af.forEachLoopAvg(duckArr));
	}

	@Test
	void testAvgWithStream() {
		Assertions.assertEquals(2, af.avgWithStream(duckArr));
	}

}
