import java.util.Currency;
import java.util.Locale;
import java.text.NumberFormat;

public class CurrencyDemo {
    public static void main(String args[]) {
        Double amount = 54628.7;
        //Locale curLocale = Locale.getDefault();
        Locale curLocale = new Locale("en", "US");

        Currency curCurrency = Currency.getInstance(curLocale);

        System.out.println(curCurrency.getDisplayName());
        System.out.println(curCurrency.getSymbol());

        NumberFormat currencyFormatter = NumberFormat.getCurrencyInstance(curLocale);
        System.out.println(currencyFormatter.format(amount));
    }
}