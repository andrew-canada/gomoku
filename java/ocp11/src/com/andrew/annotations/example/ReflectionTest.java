package com.andrew.annotations.example;

import java.lang.annotation.Annotation;
import java.util.Arrays;

import com.andrew.annotations.Versions;
import com.andrew.annotations.model.Engineer;
import com.andrew.annotations.model.Person;

public class ReflectionTest {

	public static void main(String[] args) throws NoSuchMethodException, SecurityException {
		Person andrew = new Engineer();

		// var annotations = andrew.getClass().getAnnotations();
		Annotation[] annotations = andrew.getClass().getAnnotations();
		System.out.println(annotations.length);
		Arrays.stream(annotations).forEach(System.out::println);

		Annotation[] constructorAnnotations = andrew.getClass().getConstructor().getAnnotations();
		System.out.println(constructorAnnotations.length);
		Arrays.stream(constructorAnnotations).forEach(System.out::println);
		Arrays.stream(constructorAnnotations)
				.map(a -> a instanceof com.andrew.annotations.Version version ? version.license() : null)
				.forEach(System.out::println);

		System.out.println();
		Arrays.stream(constructorAnnotations).filter(a -> a instanceof com.andrew.annotations.Versions)
				.flatMap(v -> Arrays.stream(((Versions) v).value())).map(com.andrew.annotations.Version::license)
				.forEach(System.out::println);

	}

}
