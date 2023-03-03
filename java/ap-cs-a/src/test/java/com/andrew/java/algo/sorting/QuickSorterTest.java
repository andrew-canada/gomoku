package com.andrew.java.algo.sorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

class QuickSorterTest {

	int[] numbers = { 1, 5, 23, 5, 9, 6, 23, 1, 3, -1 };
	List<Student> students = new ArrayList<>(Arrays.asList(new Student(1, "joe"), new Student(5, "bob"),
			new Student(3, "john"), new Student(-1, "a"), new Student(10, "b")));

	List<CashDonor> donorsByDonation = new ArrayList<>(Arrays.asList(new CashDonor("steve", -55, -55),
			new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55),
			new CashDonor("joe", 1, 1), new CashDonor("john", 350, 350), new CashDonor("bob", 500, 500)));
	List<CashDonor> unsortedDonors = new ArrayList<>(Arrays.asList(new CashDonor("steve", -55, -55),
			new CashDonor("bob", 500, 500), new CashDonor("steve", -55, -55), new CashDonor("steve", -55, -55),
			new CashDonor("steve", -55, -55), new CashDonor("joe", 1, 1), new CashDonor("john", 350, 350)));

	@Test
	void testQuickSortV1() {
		QuickSorterV1.quickSort(numbers);
		Assertions.assertArrayEquals(new int[] { -1, 1, 1, 3, 5, 5, 6, 9, 23, 23 }, numbers);
		Arrays.stream(numbers).forEach(System.out::println);
	}

	@Test
	void testQuickSortV2() {
		QuickSorterV2.quickSort(numbers);
		Assertions.assertArrayEquals(new int[] { -1, 1, 1, 3, 5, 5, 6, 9, 23, 23 }, numbers);
		Arrays.stream(numbers).forEach(System.out::println);
	}

	@Test
	void testQuickSortV3() {
		QuickSorterV3.quickSort(students);
		Assertions.assertEquals(new ArrayList<Student>(Arrays.asList(new Student(-1, "a"), new Student(1, "joe"),
				new Student(3, "john"), new Student(5, "bob"), new Student(10, "b"))), students);
		System.out.println();
		students.stream().forEach(System.out::println);
	}

	@Test
	void testQuickSortV4() {
		QuickSorterV4.quickSort(unsortedDonors);
		Assertions.assertEquals(donorsByDonation, unsortedDonors);
		System.out.println();
		unsortedDonors.stream().forEach(System.out::println);
	}

	@Test
	void testQuickSortV5() {
		QuickSorterV5.quickSort(unsortedDonors);
		Assertions.assertEquals(donorsByDonation, unsortedDonors);
		System.out.println();
		unsortedDonors.stream().forEach(System.out::println);
	}

}
