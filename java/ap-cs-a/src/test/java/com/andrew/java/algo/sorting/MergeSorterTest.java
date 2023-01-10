package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class MergeSorterTest {

	int[] numbers1 = { 4, 3, 2, 1 };
	int[] numbers2 = { 4, 3, 3, 2, 1 };
	int[] numbers3 = { -4, 182, 0, 1, -9 };
	int[] numbers4 = {};

	int[] numbers = { 1, 5, 23, 5, 9, 6, 23, 1, 3, -1 };
	List<Student> students = new ArrayList<>(Arrays.asList(new Student(1, "joe"), new Student(5, "bob"),
			new Student(3, "john"), new Student(-1, "a"), new Student(10, "b")));

	@Test
	void testSort() {
		MergeSorter.mergeSort(numbers1);
		Arrays.stream(numbers1).forEach(System.out::print);
		System.out.println();
		Assertions.assertArrayEquals(new int[] { 1, 2, 3, 4 }, numbers1);

		MergeSorter.mergeSort(numbers2);
		Arrays.stream(numbers2).forEach(System.out::print);
		System.out.println();
		Assertions.assertArrayEquals(new int[] { 1, 2, 3, 3, 4 }, numbers2);

		MergeSorter.mergeSort(numbers3);
		Arrays.stream(numbers3).forEach(System.out::print);
		System.out.println();
		Assertions.assertArrayEquals(new int[] { -9, -4, 0, 1, 182 }, numbers3);

		MergeSorter.mergeSort(numbers4);
		Arrays.stream(numbers4).forEach(System.out::print);
		System.out.println();
		Assertions.assertArrayEquals(new int[] {}, numbers4);
	}

	@Test
	void testMergeSortV1() {
		MergeSorterV1.mergeSort(numbers);
		Assertions.assertArrayEquals(new int[] { -1, 1, 1, 3, 5, 5, 6, 9, 23, 23 }, numbers);
		Arrays.stream(numbers).forEach(System.out::println);
	}

	@Test
	void testMergeSortV2() {
		MergeSorterV2.mergeSort(students);
		Assertions.assertEquals(new ArrayList<Student>(Arrays.asList(new Student(-1, "a"), new Student(1, "joe"),
				new Student(3, "john"), new Student(5, "bob"), new Student(10, "b"))), students);
		System.out.println();
		students.stream().forEach(System.out::println);
	}

}
