import java.util.*;
import static java.util.Locale.CANADA;
import static java.util.Locale.ITALIAN;

public class LocaleDemo {
    static void displayLocaleAttributes(Locale locale) {
        System.out.println("*** Displaying Locale Attributes ***");
        System.out.println("Display Country:" + locale.getDisplayCountry()); // name for the locale's country
        System.out.println("Display Language:" + locale.getDisplayLanguage()); // name for the locale's language
        System.out.println("Display Variant:" + locale.getDisplayVariant()); // name for the locale's variant code
        System.out.println("Display Name:" + locale.getDisplayName()); // name for the locale
        System.out.println("Language Code:" + locale.getLanguage()); // language code for this locale
        System.out.println("Country Code:" + locale.getCountry()); // country/region code for this locale
        System.out.println("Variant Code:" + locale.getVariant()); // variant code for this locale
        System.out.println("************************************\n");
    }
    public static void main(String[] args) {
        /* Default Locale */
        Locale locale=Locale.getDefault();
        System.out.println("Printing Locale attributes for default locale");
        displayLocaleAttributes(locale);

        /* Using Locale constructors to create Locale class object */
        Locale aLocale=new Locale("fr"); // Passing only locale language
        Locale bLocale=new Locale("fr", "FR"); // Passing locale language and country
        Locale cLocale=new Locale("fr", "FR", "WIN"); // Passing locale language, country and variant

        System.out.println("Printing Locale attributes for aLocale");
        displayLocaleAttributes(aLocale);
        System.out.println("Printing Locale attributes for bLocale");
        displayLocaleAttributes(bLocale);
        System.out.println("Printing Locale attributes for cLocale");
        displayLocaleAttributes(cLocale);

        /* Building Locale using Locale.Builder */
        Locale localeBuilder = new Locale.Builder().setLanguage("en").setRegion("US").build();
        System.out.println("Printing Locale attributes for localeBuilder");
        displayLocaleAttributes(localeBuilder);

        /* Using Locale constants for different countries and languages */
        System.out.println("Printing Locale attributes for Locale constants");
        System.out.println("Display Country:" + CANADA.getDisplayCountry());
        System.out.println("Display Language:" + ITALIAN.getDisplayLanguage());
    }
}