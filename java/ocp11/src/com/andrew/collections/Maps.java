package com.andrew.collections;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class Maps {

	public static void main(String[] args) {
		// red-black tree -> orders and re-sorts after every addition -> slow
		// treemap is red-black tree

		// unordered
		Map<Integer, String> unorderedMap = new HashMap<>();
		// ordered
		Map<Integer, String> orderedMap = new TreeMap<>();

		// autoboxing automatically boxes primitive int into Integer wrapper class, and
		// vice versa (unboxing)
		unorderedMap.put(1, "joe");
		unorderedMap.put(Integer.valueOf(1), "joe");
		unorderedMap.put(-1, "abc");
		unorderedMap.put(2, "bob");
		// overrides "bob"
		unorderedMap.put(2, "john");
		unorderedMap.put(4, "dave");
		unorderedMap.put(3, "steve");

		System.out.println(unorderedMap.get(1));

		System.out.println(unorderedMap.keySet());
		System.out.println(unorderedMap.values());

		unorderedMap.remove(3);
		System.out.println(unorderedMap.values());

		System.out.println(unorderedMap.containsKey(2));
		System.out.println(unorderedMap.containsValue("joe"));
		System.out.println(unorderedMap.containsKey(-2));

		orderedMap.put(1, "joe");
		orderedMap.put(-1, "abc");
		orderedMap.put(2, "bob");
		orderedMap.put(2, "john");
		orderedMap.put(4, "dave");
		orderedMap.put(3, "steve");

		System.out.println(orderedMap.values());

	}

}
