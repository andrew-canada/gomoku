import java.util.ArrayList;
import java.util.List;

public class A {

	public static void main(String[] args) {
		int[][] a = new int[4][3];
		System.out.println(a.length);
		System.out.println(a[1].length);

		List<String> b = new ArrayList<>();
		b.add(0, "a");
		b.add(0, "b");

		System.out.println(b);

	}

}
