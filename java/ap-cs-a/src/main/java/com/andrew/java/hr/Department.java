package com.andrew.java.hr;

import java.util.ArrayList;
import java.util.List;

public class Department {

	private String name;
	private int id;
	private List<Employee> employeeList = new ArrayList<>();

	public Department(String name, int id) {
		super();
		this.name = name;
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public List<Employee> getEmployeeList() {
		return employeeList;
	}

	public void assign(Employee employee) {
		employeeList.add(employee);
	}

	@Override
	public String toString() {
		return name + ", " + id;

	}
}
