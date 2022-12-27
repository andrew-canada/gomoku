/**
 * 
 */
package com.andrew.java.algo.arraylist;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.DoubleStream;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

/**
 * @author peng
 *
 */
class ArraylistOperationsTest {

	ArraylistOperations alo;
	List<Double> inputList;

	/**
	 * @throws java.lang.Exception
	 */
	@BeforeEach
	void setUp() throws Exception {
		alo = new ArraylistOperations();
		inputList = DoubleStream.iterate(0, d -> d + 1).limit(1000000).boxed().collect(Collectors.toList());
	}

	/**
	 * Test method for
	 * {@link com.andrew.java.algo.arraylist.ArraylistOperations#findMaxWithForLoop(java.util.List)}.
	 */
	@Test
	void testFindMaxWithForLoop() {
		Assertions.assertEquals(999999, alo.findMaxWithForLoop(inputList));
	}

	/**
	 * Test method for
	 * {@link com.andrew.java.algo.arraylist.ArraylistOperations#findMaxWithForEachLoop(java.util.List)}.
	 */
	@Test
	void testFindMaxWithForEachLoop() {
		Assertions.assertEquals(999999, alo.findMaxWithForEachLoop(inputList));
	}

	/**
	 * Test method for
	 * {@link com.andrew.java.algo.arraylist.ArraylistOperations#findMaxWithStream(java.util.List)}.
	 */
	@Test
	void testFindMaxWithStream() {
		Assertions.assertEquals(999999, alo.findMaxWithStream(inputList));
	}

	/**
	 * Test method for
	 * {@link com.andrew.java.algo.arraylist.ArraylistOperations#findMaxWithParallelStream(java.util.List)}.
	 */
	@Test
	void testFindMaxWithParallelStream() {
		Assertions.assertEquals(999999, alo.findMaxWithParallelStream(inputList));
	}

	/**
	 * Test method for
	 * {@link com.andrew.java.algo.arraylist.ArraylistOperations#findSumWithForLoop(java.util.List)}.
	 */
	@Test
	void testFindSumWithForLoop() {
		Assertions.assertNotEquals(999999, alo.findSumWithForLoop(inputList));
	}

	/**
	 * Test method for
	 * {@link com.andrew.java.algo.arraylist.ArraylistOperations#findSumWithForEachLoop(java.util.List)}.
	 */
	@Test
	void testFindSumWithForEachLoop() {
		Assertions.assertNotEquals(999999, alo.findSumWithForEachLoop(inputList));
	}

	@Test
	void testFindSumWithStream() {
		Assertions.assertNotEquals(999999, alo.findSumWithStream(inputList));
	}

	/**
	 * Test method for
	 * {@link com.andrew.java.algo.arraylist.ArraylistOperations#findSumWithParallelStream(java.util.List)}.
	 */
	@Test
	void testFindSumWithParallelStream() {
		Assertions.assertNotEquals(999999, alo.findSumWithParallelStream(inputList));
	}

}
