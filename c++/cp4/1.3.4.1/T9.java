import java.math.BigInteger;

public class T9 {
    public static void main(String[] args){
        int b1=16, b2=10;
        String num="FF";
        System.out.println(new BigInteger(num, b1).toString(b2));
    }
}
