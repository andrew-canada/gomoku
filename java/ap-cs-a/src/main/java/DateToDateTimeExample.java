
import java.text.ParseException;
import java.time.Instant;
import java.time.ZoneOffset;
import java.time.format.DateTimeFormatter;
import java.util.Date;

public class DateToDateTimeExample {
    public static void main(String[] args) throws ParseException {
        String dateString = "2023-01-01 01:01:01.0000000";
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss.n");
        formatter = formatter.withZone(ZoneOffset.UTC);
        Instant instant = formatter.parse(dateString, Instant::from);
        Date date = Date.from(instant);

        System.out.println(date);
    }
}
