package com.andrew.java.algo.searching;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import com.andrew.java.algo.sorting.CashDonor;
import com.andrew.java.algo.sorting.Student;

class BinarySearcherTest {

	int[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 42 };

	int[] sortedNumbers = { 1, 2, 3, 5, 6 };
	int[] unsortedNumbers = { 1, 5, 3, 2, 6 };

	int[] numbers2 = { 1, 3, 5, 7, 9, 15 };

	List<Student> sortedStudents = new ArrayList<Student>(Arrays.asList(new Student(-1, "a"), new Student(1, "joe"),
			new Student(3, "john"), new Student(5, "bob"), new Student(10, "b")));

	Student[] sortedStudentsArr = { new Student(-1, "a"), new Student(1, "joe"), new Student(3, "john"),
			new Student(5, "bob"), new Student(10, "b") };

	List<CashDonor> donorsByDonation = new ArrayList<>(Arrays.asList(new CashDonor("steve", -55, -55),
			new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55),
			new CashDonor("joe", 1, 1), new CashDonor("john", 350, 350), new CashDonor("bob", 500, 500)));
	List<CashDonor> unsortedDonors = new ArrayList<>(Arrays.asList(new CashDonor("steve", -55, -55),
			new CashDonor("bob", 500, 500), new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55),
			new CashDonor("steve", -55, -55), new CashDonor("joe", 1, 1), new CashDonor("john", 350, 350)));

	@Test
	void testLoopSearch() {
		Assertions.assertEquals(4, BinarySearcher.loopSearch(numbers, 0, numbers.length - 1, 5));
		Assertions.assertEquals(3, BinarySearcher.loopSearch(numbers, 0, numbers.length - 1, 4));
		Assertions.assertEquals(-1, BinarySearcher.loopSearch(numbers, 0, numbers.length - 1, 10));
	}

	@Test
	void testRecursiveSearch() {
		Assertions.assertEquals(4, BinarySearcher.recursiveSearch(numbers, 0, numbers.length - 1, 5));
		Assertions.assertEquals(3, BinarySearcher.recursiveSearch(numbers, 0, numbers.length - 1, 4));
		Assertions.assertEquals(-1, BinarySearcher.recursiveSearch(numbers, 0, numbers.length - 1, 14));
	}

	@Test
	void testIterativeBinarySearchV1() {
		Assertions.assertEquals(0, BinarySearcherV1.searchIteratively(sortedNumbers, 1));
		Assertions.assertEquals(4, BinarySearcherV1.searchIteratively(sortedNumbers, 6));
		Assertions.assertEquals(2, BinarySearcherV1.searchIteratively(sortedNumbers, 3));

		Assertions.assertEquals(2, BinarySearcherV1.searchIteratively(unsortedNumbers, 3));
	}

	@Test
	void testResursiveBinarySearchV1() {
		Assertions.assertEquals(0, BinarySearcherV1.searchRecursively(sortedNumbers, 1));
		Assertions.assertEquals(4, BinarySearcherV1.searchRecursively(sortedNumbers, 6));
		Assertions.assertEquals(2, BinarySearcherV1.searchRecursively(sortedNumbers, 3));

		Assertions.assertEquals(2, BinarySearcherV1.searchIteratively(unsortedNumbers, 3));
	}

	@Test
	void testLoopBinarySearchP1() {
		Assertions.assertEquals(0, BinarySearcherP1.loopBinarySearch(numbers2, 1));
		Assertions.assertEquals(4, BinarySearcherP1.loopBinarySearch(numbers2, 9));
		Assertions.assertEquals(-1, BinarySearcherP1.loopBinarySearch(numbers2, 111));
	}

	@Test
	void testRecursiveBinarySearchP1() {
		Assertions.assertEquals(0, BinarySearcherP1.recursiveBinarySearch(numbers2, 1));
		Assertions.assertEquals(4, BinarySearcherP1.recursiveBinarySearch(numbers2, 9));
		Assertions.assertEquals(-1, BinarySearcherP1.recursiveBinarySearch(numbers2, 111));
	}

	@Test
	void testBinarySearchRecursiveV2() {
		Assertions.assertEquals(1, BinarySearcherV2.binarySearchRecursive(sortedStudents, new Student(1, "joe")));
		Assertions.assertEquals(-1, BinarySearcherV2.binarySearchRecursive(sortedStudents, new Student(11, "bb")));
	}

	@Test
	void testBinarySearchIterativeV2() {
		Assertions.assertEquals(1, BinarySearcherV2.binarySearchIterative(sortedStudents, new Student(1, "joe")));
		Assertions.assertEquals(-1, BinarySearcherV2.binarySearchIterative(sortedStudents, new Student(11, "bb")));
	}

	@Test
	void testBinarySearchRecursiveV3() {
		Assertions.assertEquals(1, BinarySearcherV3.searchRecursively(sortedStudentsArr, new Student(1, "joe")));
		Assertions.assertEquals(-1, BinarySearcherV3.searchRecursively(sortedStudentsArr, new Student(11, "bb")));
	}

	@Test
	void testBinarySearchIterativeV3() {
		Assertions.assertEquals(1, BinarySearcherV3.searchIteratively(sortedStudentsArr, new Student(1, "joe")));
		Assertions.assertEquals(-1, BinarySearcherV3.searchIteratively(sortedStudentsArr, new Student(11, "bb")));
	}

	@Test
	void testBinarySearchRecursiveV4() {
		Assertions.assertEquals(6,
				BinarySearcherV4.binarySearchRecursively(donorsByDonation, new CashDonor("bob", 500, 500)));
		Assertions.assertEquals(4,
				BinarySearcherV4.binarySearchRecursively(donorsByDonation, new CashDonor("joe", 1, 1)));
	}

	@Test
	void testBinarySearchIterativeV4() {
		Assertions.assertEquals(6,
				BinarySearcherV4.binarySearchIteratively(donorsByDonation, new CashDonor("bob", 500, 500)));
		Assertions.assertEquals(4,
				BinarySearcherV4.binarySearchIteratively(donorsByDonation, new CashDonor("joe", 1, 1)));
	}

}
