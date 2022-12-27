package com.andrew.datatypes.lists;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class ListMain {

	public static void main(String[] args) {

		int[] numberArray = { 5, 743, 23 };
		System.out.println("array class name : " + numberArray.getClass().getName());
		System.out.println("print array: ");
		for (int i = 0; i < numberArray.length; i++) {
			System.out.println(numberArray[i]);
		}

		List arrayToList = Arrays.asList(numberArray);
		// arrayToList.add(23); can't add to list converted from array
		System.out.println("list converted from array class name : " + arrayToList.getClass().getName());

		List numberList = new ArrayList<>();
		System.out.println("list class name : " + numberList.getClass().getName());
		numberList.add(56);
		numberList.add(78);
		numberList.add(1, -1);

		System.out.println("print unsorted number list");
		numberList.forEach((number) -> {
			System.out.println(number);
		});
		Collections.sort(numberList);
		System.out.println("print sorted number list: ");
		System.out.println(numberList);

		List<String> colorList = new ArrayList<String>();
		colorList.add("blue");
		colorList.add("red");
		colorList.add(1, "green");
		System.out.println("printing color list: ");
		System.out.println(colorList);

		// int[] listToArray = numberList.toArray(new int[0]); can't convert primitive
		// list to array
		String[] listToArray = colorList.toArray(new String[0]);
		for (int i = 0; i < listToArray.length; i++) {
			System.out.println(listToArray[i]);
		}

		LinkedList<String> leaderboard = new LinkedList<String>();
		leaderboard.add("joe");
		leaderboard.addFirst("1");
		System.out.println(leaderboard);
	}

}
