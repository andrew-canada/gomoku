package com.andrew.exercises.model;

public interface ProductFilter<T> {

	public boolean accept(T item);

}
