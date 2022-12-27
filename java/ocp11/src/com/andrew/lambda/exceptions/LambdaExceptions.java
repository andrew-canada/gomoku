package com.andrew.lambda.exceptions;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

import com.andrew.model.Student;
import com.andrew.model.util.StudentSample;

/*
 * write list of products to file
 * 		1. FileWriter to open file
 * 		2. use try/catch to catch exception
 * 		3. write products to file
 */

public class LambdaExceptions {

	public static void main(String[] args) {

		new StudentSample();
		List<Student> studentList = StudentSample.getStudentList();

		try {
			FileWriter fw = new FileWriter("studentsLambda.txt");
			studentList.forEach(student -> {
				try {
					fw.write(student.toString());
					fw.append("a");
					fw.append(System.lineSeparator());
				} catch (IOException e) {
					System.out.println("lambda exception interior");
				}
			});
			fw.write("----------------");
			fw.close();
		} catch (IOException ioe) {
			System.out.println("lambda exception exterior");
		}

		try {
			FileWriter fw = new FileWriter("studentsLoop.txt");
			for (Student student : studentList) {
				fw.write(student.toString());
				fw.append(System.lineSeparator());
			}
			fw.close();
		} catch (IOException ioe) {
			System.out.println("loop exception");
		}

		try (FileWriter fw = new FileWriter("studentsLoopResource.txt")) {
			fw.write("try/catch with resources - loop");
			fw.append(System.lineSeparator());
			for (Student student : studentList) {
				fw.write(student.toString());
				fw.append(System.lineSeparator());
			}
			fw.close();
		} catch (IOException ioe) {
			System.out.println("loop exception");
		}

	}

}
