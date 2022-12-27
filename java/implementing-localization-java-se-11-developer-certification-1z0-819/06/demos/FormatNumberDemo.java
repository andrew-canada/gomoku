import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Locale;

public class FormatNumberDemo {
    public static void main(String args[]) {
        double num = 32360.856974;

        NumberFormat nf = NumberFormat.getInstance(new Locale("en", "US"));
        nf.setMaximumFractionDigits(2);
        String value = nf.format(num);
        System.out.println("Number formatted for the locale - " + value);

        DecimalFormat df = new DecimalFormat("$#0.00");
        String valueDf = df.format(num);
        System.out.println("Number formatted using DecimalFormat - " + valueDf);
    }
}