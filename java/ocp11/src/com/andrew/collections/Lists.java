package com.andrew.collections;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Lists {

	public static void main(String[] args) {
		List arrayList1 = new ArrayList();
		System.out.println(arrayList1);

		// with inital capacity
		List arrayList2 = new ArrayList(5);
		arrayList2.add(2);
		System.out.println(arrayList2);

		// same contents
		List arrayList3 = new ArrayList(arrayList2);
		System.out.println(arrayList3);

		List<String> vehicles = new ArrayList();
		vehicles.add("car");
		vehicles.add("truck");
		vehicles.add("bus");
		vehicles.add(0, "bike");
		vehicles.forEach(vehicle -> {
			System.out.println(vehicle);
		});

		Object[] vehicleArray = vehicles.toArray();
		System.out.println(vehicleArray[0]);

		// ids needs to be Integer[] because int[] is primitive
		Integer[] ids = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
		List idList = Arrays.asList(ids);
		idList.parallelStream().forEach(System.out::println);

		LinkedList<String> names = new LinkedList<>();
		names.add("jfk");
		names.addFirst("fdr");
		names.addLast("ddr");
		System.out.println(names);
		names.removeFirst();
		System.out.println(names);
		System.out.println(names.getLast());

		List<Integer> numbers = new ArrayList<>();
		numbers.add(5);
		numbers.add(-9);
		numbers.add(578);
		numbers.add(2);
		numbers.stream().forEach(System.out::println);
		System.out.println();
		Collections.sort(numbers);
		numbers.stream().forEach(System.out::println);

	}

}
