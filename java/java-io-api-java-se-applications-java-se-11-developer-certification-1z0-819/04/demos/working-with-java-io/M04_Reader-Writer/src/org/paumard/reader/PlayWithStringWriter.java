package org.paumard.reader;

import java.io.IOException;
import java.io.StringWriter;

public class PlayWithStringWriter {

	public static void main(String[] args) {

		try (StringWriter writer = new StringWriter();) {

			writer.write("Hello world!");

			writer.flush();

			StringBuffer buffer = writer.getBuffer();
			String string = buffer.toString();

			System.out.println(string);

		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
