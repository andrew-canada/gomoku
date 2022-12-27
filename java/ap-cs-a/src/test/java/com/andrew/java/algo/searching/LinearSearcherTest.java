package com.andrew.java.algo.searching;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import com.andrew.java.algo.array.DebugDuck;

class LinearSearcherTest {

	LinearSearcher ls;
	DebugDuck[] duckArray = { new DebugDuck("d1", 1), new DebugDuck("d1", 1), new DebugDuck("d2", 2),
			new DebugDuck("d3", 3) };
	List<DebugDuck> duckList;
	List<DebugDuck> duckListAfterRemoval;

	@BeforeEach
	void setUp() throws Exception {
		ls = new LinearSearcher();
		duckList = new ArrayList<>(Arrays.asList(new DebugDuck("d1", 1), new DebugDuck("d1", 1), new DebugDuck("d2", 2),
				new DebugDuck("d3", 3)));
		duckListAfterRemoval = new ArrayList<>(Arrays.asList(new DebugDuck("d2", 2), new DebugDuck("d3", 3)));
	}

	@Test
	void testSearchAgeWithForLoop() {
		Assertions.assertNotEquals(2, ls.searchAgeWithForLoop(duckArray, 3));
		Assertions.assertEquals(3, ls.searchAgeWithForLoop(duckArray, 3));
	}

	@Test
	void testSearchAgeWithForEachLoop() {
		Assertions.assertNotEquals(2, ls.searchAgeWithForEachLoop(duckList, 3));
		Assertions.assertEquals(3, ls.searchAgeWithForEachLoop(duckList, 3));
	}

	@Test
	void testFindDuckByNameUsingStream() {
		Assertions.assertNotEquals(duckList.get(2), ls.findDuckByNameUsingStream(duckList, "d3"));
		Assertions.assertEquals(duckList.get(3), ls.findDuckByNameUsingStream(duckList, "d3"));
	}

	@Test
	void testRemoveDuckWithForLoopForward() {
		List<DebugDuck> ddl = ls.removeDuckWithForLoopForward(duckList, 1);
		ddl.stream().forEach(System.out::print);
		Assertions.assertEquals(duckListAfterRemoval, ddl);
	}

	@Test
	void testRemoveDuckWithForLoopBackward() {
		List<DebugDuck> ddl = ls.removeDuckWithForLoopBackward(duckList, 1);
		ddl.stream().forEach(System.out::print);
		Assertions.assertEquals(duckListAfterRemoval, ddl);
	}

}
