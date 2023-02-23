
public class T {

    public static void add(int a) {
        for (int i = 0; i < 10; i++) {
            if (i == a) {
                System.out.println("found");
                return;
            }
        }
        System.out.println("not found");
    }

    public static void main(String[] args) {
        add(1);
        String s = "abc";
        String[] names = { "bob", "joe", null, "abc" };
        for (String n : names) {
            if (s.equals(n)) {
                System.out.println("equal");
            }
        }

    }

}
