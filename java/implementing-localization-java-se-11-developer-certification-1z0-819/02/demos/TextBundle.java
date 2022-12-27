import java.util.*;

public class TextBundle {
    public static void main(String[] args) {
        Locale usLocale = new Locale("en", "US");
        ResourceBundle textBundleUs = ResourceBundle.getBundle("TextBundle", usLocale);
        System.out.println(textBundleUs.getString("msg1"));
        System.out.println(textBundleUs.getString("msg2"));

        Locale inLocale = new Locale("hi", "IN");
        try {
            ResourceBundle textBundleIn = ResourceBundle.getBundle("TextBundle_in", inLocale);
            System.out.println(textBundleIn.getString("msg1"));
            System.out.println(textBundleIn.getString("msg2"));
        } catch(MissingResourceException e) {
            System.out.println(textBundleUs.getString("msg1"));
            System.out.println(textBundleUs.getString("msg2"));
        }
    }
}
