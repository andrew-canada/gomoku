package com.andrew.java.algo.array;

import java.util.Arrays;
import java.util.Optional;

import org.apache.commons.lang3.tuple.ImmutablePair;

public class MaxAndMinFinder {

    public double findMax(double[] input) throws NullPointerException {
        if (Optional.ofNullable(input).isEmpty()) {
            throw new NullPointerException("input is null, expected double arr.");
        } else {
            double max = input[0];
            for (int i = 1; i < input.length; i++) {
                if (input[i] > max) {
                    max = input[i];
                }
            }
            return max;
        }
    }

    public double findMaxWithStream(double[] input) {
        return Arrays.stream(input).max().orElse(0);
    }

    public double findMin(double[] input) {
        double min = input[0];
        for (int i = 1; i < input.length; i++) {
            if (input[i] < min) {
                min = input[i];
            }
        }
        return min;
    }

    public ImmutablePair<Integer, Double> findMaxValAndIndex(double[] input) {
        double max = input[0];
        int maxIndex = 0;
        for (int i = 1; i < input.length; i++) {
            if (input[i] > max) {
                max = input[i];
                maxIndex = i;
            }
        }
        return new ImmutablePair<>(Integer.valueOf(maxIndex), Double.valueOf(max));
    }
}
