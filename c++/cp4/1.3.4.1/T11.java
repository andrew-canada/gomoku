import java.math.BigInteger;

public class T11 {
    public static void main(String[] args) {
        BigInteger num = new BigInteger("123");
        System.out.println(num.isProbablePrime(1) ? "Prime" : "Composite");
    }
}
