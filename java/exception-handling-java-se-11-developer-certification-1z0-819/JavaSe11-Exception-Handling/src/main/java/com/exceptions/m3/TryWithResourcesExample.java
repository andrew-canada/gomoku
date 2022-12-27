package com.exceptions.m3;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class TryWithResourcesExample {

	public static void main(String[] args) throws IOException {

		try (FileInputStream in = new FileInputStream("in1.txt");
				FileOutputStream out = new FileOutputStream("out.txt")) {
			out.write(in.readAllBytes());
		} catch (FileNotFoundException fnfe) {
			System.out.println("FileNotFoundException" + fnfe.getMessage());
			fnfe.printStackTrace();
		}

	}
}
