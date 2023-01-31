package com.andrew.java.algo.searching;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import com.andrew.java.algo.array.DebugDuck;
import com.andrew.java.algo.sorting.CashDonor;
import com.andrew.java.algo.sorting.Student;

class LinearSearcherTest {

	LinearSearcher ls;
	DebugDuck[] duckArray = { new DebugDuck("d1", 1), new DebugDuck("d1", 1), new DebugDuck("d2", 2),
			new DebugDuck("d3", 3) };
	List<DebugDuck> duckList;
	List<DebugDuck> duckListAfterRemoval;

	int[] unsortedNumbers = { 1, 5, 3, 2, 6 };
	int[] sortedNumbers = { 1, 2, 3, 5, 6 };

	List<Student> unsortedStudents = new ArrayList<>(Arrays.asList(new Student(1, "joe"), new Student(5, "bob"),
			new Student(3, "john"), new Student(-1, "a"), new Student(10, "b")));
	List<Student> sortedStudents = new ArrayList<Student>(Arrays.asList(new Student(-1, "a"), new Student(1, "joe"),
			new Student(3, "john"), new Student(5, "bob"), new Student(10, "b")));

	Student[] unsortedStudentsArr = { new Student(1, "joe"), new Student(5, "bob"), new Student(3, "john"),
			new Student(-1, "a"), new Student(10, "b") };
	Student[] sortedStudentsArr = { new Student(-1, "a"), new Student(1, "joe"), new Student(3, "john"),
			new Student(5, "bob"), new Student(10, "b") };

	List<CashDonor> donorsByDonation = new ArrayList<>(Arrays.asList(new CashDonor("steve", -55, -55),
			new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55),
			new CashDonor("joe", 1, 1), new CashDonor("john", 350, 350), new CashDonor("bob", 500, 500)));
	List<CashDonor> unsortedDonors = new ArrayList<>(Arrays.asList(new CashDonor("steve", -55, -55),
			new CashDonor("bob", 500, 500), new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55),
			new CashDonor("steve", -55, -55), new CashDonor("joe", 1, 1), new CashDonor("john", 350, 350)));

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

	@Test
	void testUnsortedSearchV1() {
		Assertions.assertEquals(0, SequentialSearcherV1.searchUnsorted(unsortedNumbers, 1));
		Assertions.assertEquals(4, SequentialSearcherV1.searchUnsorted(unsortedNumbers, 6));
		Assertions.assertEquals(2, SequentialSearcherV1.searchUnsorted(unsortedNumbers, 3));
	}

	@Test
	void testSortedAscendingSearchV1() {
		Assertions.assertEquals(-1, SequentialSearcherV1.searchSortedAscending(sortedNumbers, 0));
		Assertions.assertEquals(-1, SequentialSearcherV1.searchSortedAscending(sortedNumbers, 7));
		Assertions.assertEquals(0, SequentialSearcherV1.searchSortedAscending(sortedNumbers, 1));
	}

	@Test
	void testSequentialSearchUnsortedV2() {
		Assertions.assertEquals(0,
				SequentialSearcherV2.sequentialSearchUnsorted(unsortedStudents, new Student(1, "joe")));
		Assertions.assertEquals(-1,
				SequentialSearcherV2.sequentialSearchUnsorted(unsortedStudents, new Student(11, "bb")));
	}

	@Test
	void testSequentialSearchSortedV2() {
		Assertions.assertEquals(1,
				SequentialSearcherV2.sequentialSearchUnsorted(sortedStudents, new Student(1, "joe")));
		Assertions.assertEquals(-1,
				SequentialSearcherV2.sequentialSearchUnsorted(sortedStudents, new Student(11, "bb")));
	}

	@Test
	void testSequentialSearchUnsortedV3() {
		Assertions.assertEquals(0, LinearSearcherV3.linearSearchUnsorted(unsortedStudentsArr, new Student(1, "joe")));
		Assertions.assertEquals(-1, LinearSearcherV3.linearSearchUnsorted(unsortedStudentsArr, new Student(11, "bb")));
	}

	@Test
	void testSequentialSearchSortedV3() {
		Assertions.assertEquals(1, LinearSearcherV3.linearSearchSorted(sortedStudentsArr, new Student(1, "joe")));
		Assertions.assertEquals(-1, LinearSearcherV3.linearSearchSorted(sortedStudentsArr, new Student(11, "bb")));
	}

	@Test
	void testLinearSearchUnsortedV4() {
		Assertions.assertEquals(-1,
				LinearSearcherV4.linearSearchUnsorted(unsortedDonors, new CashDonor("stev", -55, -55)));
		Assertions.assertEquals(5, LinearSearcherV4.linearSearchUnsorted(unsortedDonors, new CashDonor("joe", 1, 1)));
	}

	@Test
	void testLinearSearchSortedV4() {
		Assertions.assertEquals(0,
				LinearSearcherV4.linearSearchSorted(donorsByDonation, new CashDonor("steve", -55, -55)));
		Assertions.assertEquals(5,
				LinearSearcherV4.linearSearchSorted(donorsByDonation, new CashDonor("john", 350, 350)));
	}
}
