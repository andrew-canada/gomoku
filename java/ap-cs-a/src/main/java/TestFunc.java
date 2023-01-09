import java.util.ArrayList;
import java.util.List;

public class TestFunc {
    private String line;

    public ArrayList<String> getLineWords() {
        String remainingString = line;
        ArrayList<String> words = new ArrayList<>();
        int startIndex = 0;
        while (remainingString.indexOf(" ") != -1) {
            words.add(remainingString.substring(0, remainingString.indexOf(" ")));
            startIndex = remainingString.indexOf(" ") + 1;
            remainingString = remainingString.substring(startIndex);
        }
        words.add(remainingString);
        return words;
    }

    public static void main(String[] args) {
        TestFunc t = new TestFunc();
        t.line = "ab cd e f";
        List<String> words = t.getLineWords();
        words.stream().forEach(System.out::println);

        String word = "hello";
        System.out.println(word.substring(0, 1));

    }

}
