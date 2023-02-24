import java.util.ArrayList;
import java.util.List;

public class AutoboxTest {

    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<>();
        nums.add(1);
        nums.add(2);
        nums.stream().forEach(System.out::println);
        if (nums.get(0) < nums.get(1)) {
            System.out.println("aa\n");
        }

    }

}
