package com.andrew.java.algo.array;

import java.util.Arrays;
import java.util.Optional;

public class AvgFinder {

	public double forLoopAvg(DebugDuck[] duckArr) throws NullPointerException {
		if (Optional.ofNullable(duckArr).isEmpty()) {
			throw new NullPointerException("input is null, expected DebugDuck arr");
		}
		int total = 0;
		for (int i = 0; i < duckArr.length; i++) {
			total += duckArr[i].getAge();
		}
		return (double) total / duckArr.length;
	}

	public double forEachLoopAvg(DebugDuck[] duckArr) {
		int total = 0;
		for (DebugDuck d : duckArr) {
			total += d.getAge();
		}
		return (double) total / duckArr.length;
	}

	public double avgWithStream(DebugDuck[] duckArr) {
		return Arrays.stream(duckArr).mapToInt(DebugDuck::getAge).average().orElse(0);
	}
}
