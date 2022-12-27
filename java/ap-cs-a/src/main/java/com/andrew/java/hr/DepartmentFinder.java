package com.andrew.java.hr;

import java.util.List;

public class DepartmentFinder {

	public static Department find(List<Department> departmentList, String departmentName) {
		for (Department d : departmentList) {
			if (d.getName().equalsIgnoreCase(departmentName)) {
				return d;
			}
		}
		return null;
	}
}
