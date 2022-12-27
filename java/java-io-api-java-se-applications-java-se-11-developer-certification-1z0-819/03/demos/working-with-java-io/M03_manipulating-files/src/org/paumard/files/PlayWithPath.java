package org.paumard.files;

import java.nio.file.Path;
import java.nio.file.Paths;

public class PlayWithPath {

	public static void main(String[] args) {

		Path path1 = Paths.get("videos/");
		Path path2 = Path.of("images/pngs/");

		System.out.println("path1 = " + path1);
		System.out.println("path2 = " + path2);
		System.out.println("path1 = " + path1.getClass());

		Path relativize = path1.relativize(path2);
		System.out.println("relativize = " + relativize);
	}
}
