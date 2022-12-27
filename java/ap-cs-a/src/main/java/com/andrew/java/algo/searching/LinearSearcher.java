package com.andrew.java.algo.searching;

import java.util.List;
import java.util.stream.Collectors;

import com.andrew.java.algo.array.DebugDuck;

public class LinearSearcher {

    public int searchAgeWithForLoop(DebugDuck[] inputArray, int duckAge) {
        for (int i = 0; i < inputArray.length; i++) {
            if (inputArray[i].getAge() == duckAge) {
                return i;
            }
        }
        return -1;
    }

    public int searchAgeWithForEachLoop(List<DebugDuck> inputList, int duckAge) {
        int index = 0;
        for (DebugDuck dd : inputList) {
            if (dd.getAge() == duckAge) {
                return index;
            }
            index += 1;
        }
        return -1;
    }

    public DebugDuck findDuckByNameUsingStream(List<DebugDuck> inputList, String duckName) {
        return inputList.stream().filter(d -> d.getName().equals(duckName)).findFirst().orElse(null);
    }

    public List<DebugDuck> removeDuckWithForLoopForward(List<DebugDuck> inputList, int duckAge) {
        List<DebugDuck> newList = inputList.stream().collect(Collectors.toList());
        for (int i = 0; i < newList.size(); i++) {
            if (newList.get(i).getAge() == duckAge) {
                newList.remove(i);
                i -= 1;
            }
        }
        return newList;
    }

    public List<DebugDuck> removeDuckWithForLoopBackward(List<DebugDuck> inputList, int duckAge) {
        List<DebugDuck> newList = inputList.stream().collect(Collectors.toList());
        for (int i = newList.size() - 1; i >= 0; i--) {
            if (newList.get(i).getAge() == duckAge) {
                newList.remove(i);
            }
        }
        return newList;
    }
}
