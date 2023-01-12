import java.util.Arrays;

public class A {

    public static void main(String[] args) {
        int a = 5;
        int b = (int) Math.sqrt(a);
        System.out.println(b);
        System.out.println(Math.pow(b, 2));
        System.out.println(b == a);

        Integer[] numbers = new Integer[5];
        Arrays.stream(numbers).forEach(System.out::println);
        System.out.println();
        int[] numbers2 = new int[5];
        Arrays.stream(numbers2).forEach(System.out::println);
        int[][] arr = { { 1, 11 }, { 2, 22 } };
        for (int[] a1 : arr) {
            Arrays.stream(a1).forEach(System.out::print);
        }
        System.out.println(getNumber(1));
    }

    private static double getNumber(int i) {
        if (i == 1) {
            return 1;
        } else {
            return 1;
        }

    }

    private static boolean isTrue(int i) {
        return Math.random() < 0.4;
    }

}
