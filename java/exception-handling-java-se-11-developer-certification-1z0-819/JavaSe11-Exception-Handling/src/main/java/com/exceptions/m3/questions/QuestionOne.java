package com.exceptions.m3.questions;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class QuestionOne {

	// does not compile - an unhandled exception thrown by close() - we must wrap
	// into another try/catch
	public static void main(String[] args) {

		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("file.txt"));
		} catch (FileNotFoundException ex) {
			System.out.println("file not found exception");
		} finally {
			try {
				if (br != null) {
					br.close();
				}
			} catch (IOException ioe) {
				System.out.println("io exception");
			}
		}
	}
}
