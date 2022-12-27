package com.andrew.collections.stream;

import java.math.BigInteger;
import java.util.UUID;
import java.util.stream.Stream;

public class GeneratingAndBuilding {

	public static void main(String[] args) {
		Stream<UUID> uuidList = Stream.generate(UUID::randomUUID);
		uuidList.limit(5).forEach(System.out::println);

		Stream<BigInteger> multiplesOf2 = Stream.iterate(BigInteger.ONE, n -> n.multiply(BigInteger.TWO));
		multiplesOf2.limit(5).forEach(System.out::println);

		Stream<Character> alphabet = Stream.iterate('a', c -> c <= 'z', c -> (char) (c + 1));
		alphabet.forEach(System.out::println);

		Stream.Builder<String> strBuilder = Stream.builder();
		strBuilder.add("a");
		strBuilder.add("b");
		strBuilder.add("c");
		Stream<String> letters = strBuilder.build();
		letters.forEach(System.out::println);

	}

}
