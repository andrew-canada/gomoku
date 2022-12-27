package com.andrew.java.hr;

import java.util.ArrayList;
import java.util.List;

public class HrSystem {

	public static void main(String[] args) {
		// create department
		Department hr = new Department("HR", 1);
		Department it = new Department("IT", 2);
		Department finance = new Department("FINANCE", 3);

		List<Department> departmentList = new ArrayList<>();
		departmentList.add(hr);
		departmentList.add(it);
		departmentList.add(finance);
		System.out.println(departmentList);

		// create employee
		Employee a = new Employee("a", 1);
		Employee b = new Employee("b", 2);
		Employee c = new Employee("c", 3);
		Employee d = new Employee("d", 4);

		System.out.println(b);
		System.out.println(hr);

		// assign employee to department
		hr.assign(a);
		it.assign(b);
		finance.assign(c);
		// find department

		DepartmentFinder.find(departmentList, "HR").assign(d);

		// print all employees in a department
		System.out.println(hr.getEmployeeList());
		System.out.println(it.getEmployeeList());
		System.out.println(finance.getEmployeeList());

	}

}
