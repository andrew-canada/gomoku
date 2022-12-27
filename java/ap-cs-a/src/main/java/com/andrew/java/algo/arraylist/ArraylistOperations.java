package com.andrew.java.algo.arraylist;

import java.util.List;
import java.util.Optional;

/**
 * @author peng
 *
 */
public class ArraylistOperations {

	/**
	 * @throws java.lang.Exception hahah
	 */
	public double findMaxWithForLoop(List<Double> inputList) throws NullPointerException {
		if (Optional.ofNullable(inputList).isEmpty()) {
			throw new NullPointerException("input is null, expected list of double");
		} else {
			double max = inputList.get(0);
			for (int i = 1; i < inputList.size(); i++) {
				if (inputList.get(i) > max) {
					max = inputList.get(i);
				}
			}
			return max;
		}
	}

	public double findMaxWithForEachLoop(List<Double> inputList) {
		double max = Double.MIN_VALUE;
		for (Double value : inputList) {
			if (value > max) {
				max = value;
			}
		}
		return max;
	}

	public double findMaxWithStream(List<Double> inputList) {
		return inputList.stream().mapToDouble(Double::doubleValue).max().orElse(0);
	}

	public double findMaxWithParallelStream(List<Double> inputList) {
		return inputList.parallelStream().mapToDouble(Double::doubleValue).max().orElse(0);
	}

	public double findSumWithForLoop(List<Double> inputList) {
		double sum = 0;
		for (int i = 0; i < inputList.size(); i++) {
			sum += inputList.get(i);
		}
		return sum;
	}

	public double findSumWithForEachLoop(List<Double> inputList) {
		double sum = 0;
		for (Double value : inputList) {
			sum += value;
		}
		return sum;
	}

	public double findSumWithStream(List<Double> inputList) {
		return inputList.stream().mapToDouble(Double::doubleValue).sum();
	}

	public double findSumWithParallelStream(List<Double> inputList) {
		return inputList.parallelStream().mapToDouble(Double::doubleValue).sum();
	}
}
