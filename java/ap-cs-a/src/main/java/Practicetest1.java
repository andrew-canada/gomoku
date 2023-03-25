import java.util.Arrays;

public class Practicetest1 {

	public static void main(String[] args) {
		int[] a = { -1, -2, -3 };
		int c = 0;
		for (int i = 0; i < 3; i++) {
			if (a[i] >= 0) {
				a[c] = a[i];
				c++;
			}
		}
		Arrays.stream(a).forEach(System.out::println);

		System.out.println((int) (1.1 + 2));
	}

}
