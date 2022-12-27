import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.FormatStyle;
import java.util.Locale;
import java.util.TimeZone;

public class DateTimeDemo {
    public static void main(String args[]) {
        /* Obtaining local date and time */
        //LocalDateTime localDateTime = LocalDateTime.of(2021,3,7,12,44,36);
        LocalDateTime localDateTime = LocalDateTime.now();
        LocalTime localTime = localDateTime.toLocalTime();

        System.out.println("DayOfMonth - " + localDateTime.getDayOfMonth());
        System.out.println("Month - " + localDateTime.getMonth());
        System.out.println("Hour - " + localTime.getHour());
        System.out.println("Minute - " + localTime.getMinute());

        /* Formatting date and time */
        String pattern = "dd-MMMM-yyyy HH:mm:ss.SSS";
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern(pattern);
        String formatDateTime = localDateTime.format(dateTimeFormatter);
        System.out.println("Default Format Date Time - " + formatDateTime);

        Locale.setDefault(Locale.FRANCE);
        DateTimeFormatter localDateTimeFormatter = DateTimeFormatter.ofLocalizedDateTime(FormatStyle.MEDIUM);
        String localFormatDateTime = localDateTime.format(localDateTimeFormatter);
        System.out.println("Locale Format Date Time - " + localFormatDateTime);

        /* Adding time-zone */
        Locale.setDefault(Locale.GERMANY);
        TimeZone localTimeZone = TimeZone.getDefault();
        System.out.println("TimeZone - " + localTimeZone.getDisplayName(Locale.getDefault()));

        ZonedDateTime zonedDateTime = ZonedDateTime.now(ZoneId.of("Asia/Tokyo"));
        System.out.println("ZonedDateTime - " + zonedDateTime.toString());
        System.out.println("DayOfMonth - " + zonedDateTime.toLocalDateTime().getDayOfMonth());

        /* Time stamp */
        Timestamp timestamp = Timestamp.valueOf(localDateTime);
        System.out.println("Timestamp - " + timestamp.toString());
    }
}
