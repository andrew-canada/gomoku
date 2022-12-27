package com.andrew.collections;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class ComparableAndComparatorPerson implements Comparable<ComparableAndComparatorPerson> {

	private String name;
	private int age;

	public ComparableAndComparatorPerson(String name, int age) {
		this.name = name;
		this.age = age;
	}

	// comparable compares an object of a class with an instance of the same class
	@Override
	// must implement compareTo()
	public int compareTo(ComparableAndComparatorPerson p) {
		return this.age - p.age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public static void main(String[] args) {
		List<ComparableAndComparatorPerson> people = new ArrayList<>();
		people.add(new ComparableAndComparatorPerson("old", 30));
		people.add(new ComparableAndComparatorPerson("young", 10));
		people.add(new ComparableAndComparatorPerson("mid", 20));

		// comparable allows sorting objects
		Collections.sort(people);

		List<String> sortedList1 = people.stream().map(ComparableAndComparatorPerson::getName).toList();
		System.out.println(sortedList1);

		// comparator EXTERNALLY compares 2 objects of a class -> MULTIPLE comparison
		// factors
		Comparator<ComparableAndComparatorPerson> personComparator = new Comparator<>() {
			// must implement compare()
			public int compare(ComparableAndComparatorPerson p1, ComparableAndComparatorPerson p2) {
				return p1.getAge() - p2.getAge();
			}
		};

		people.add(new ComparableAndComparatorPerson("old", 30));
		people.add(new ComparableAndComparatorPerson("young", 10));
		people.add(new ComparableAndComparatorPerson("mid", 20));

		Collections.sort(people, personComparator);

		List<String> sortedList2 = people.stream().map(ComparableAndComparatorPerson::getName)
				.collect(Collectors.toList());
		System.out.println(sortedList2);

	}

}
