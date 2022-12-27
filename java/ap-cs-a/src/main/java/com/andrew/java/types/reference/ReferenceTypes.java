package com.andrew.java.types.reference;

import java.awt.Point;
// in order to use a class from another package, import it
import java.util.Date;

public class ReferenceTypes {

	public static void main(String[] args) {

		// new operator allocates memory
		// variable now is an instance of the Date class
		Date now = new Date();

		// objects have members, primitive types do not
		now.getTime();
		System.out.println(now.getTime());
		System.out.println(now);

		byte a = 1;
		byte b = a;
		a = 2;
		System.out.println(b);

		// reference types only reference values, they only store memory addresses
		// point1 references the point object
		Point point1 = new Point(1, 1);

		// point2 references the same point object as point1
		Point point2 = point1;

		// because the 2 points reference the same object, changing the object in either
		// reference will change the value
		point1.x = 2;
		System.out.println(point2);

		// show how to print an object content
		Person andrew = new Person("andrew", (byte) 13);
		System.out.println(andrew);
		PersonWithToString goodAndrew = new PersonWithToString("andrew", (byte) 13);
		System.out.println(goodAndrew);

	}

}
