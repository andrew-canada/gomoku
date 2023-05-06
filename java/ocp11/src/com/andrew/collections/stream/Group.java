package com.andrew.collections.stream;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.stream.Collectors;

public class Group {
	public static void main(String[] args) {
		List<Person> people = Arrays.asList(new Person("Alice", "New York"), new Person("Bob", "Los Angeles"),
				new Person("Charlie", "New York"), new Person("Dave", "Chicago"));

		Map<City, List<Person>> peopleByCity = people.stream()
				.collect(Collectors.groupingBy(p -> new City(p.getCity()), Collectors.toList()));

		System.out.println(peopleByCity);
	}
}

class Person {
	private String name;
	private String city;

	public Person(String name, String city) {
		this.name = name;
		this.city = city;
	}

	public String getName() {
		return name;
	}

	public String getCity() {
		return city;
	}

	@Override
	public String toString() {
		return "Person{" + "name='" + name + '\'' + ", city='" + city + '\'' + '}';
	}
}

class City {
	private String name;

	public City(String name) {
		this.name = name;
	}

	public String getName() {
		return name;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;
		City city = (City) o;
		return Objects.equals(name, city.name);
	}

	@Override
	public int hashCode() {
		return Objects.hash(name);
	}

	@Override
	public String toString() {
		return "City{" + "name='" + name + '\'' + '}';
	}
}
