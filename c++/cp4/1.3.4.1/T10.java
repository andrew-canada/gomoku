public class T10 {
    public static void main(String[] args) {
        String s = "line: a70 and z72 will be replaced, aa24 and a872 will not";
        System.out.println(s.replaceAll("\\b[a-z][0-9][0-9]\\b", "***"));
    }
}
