package com.andrew.model;

public interface MarkFilter<T> {

	public boolean accept(T s);

}
