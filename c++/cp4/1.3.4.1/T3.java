import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Date;

public class T3 {
    public static void main(String[] args) {
        String[] days = { "", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        Calendar day = new GregorianCalendar(2010, 7, 9);
        System.out.println(days[day.get(Calendar.DAY_OF_WEEK)]);
        Date now = new Date();
        long elapsed = (now.getTime() - day.getTime().getTime()) / (1000 * 60 * 60 * 24);
        System.out.println(elapsed + " days elapsed");
    }
}
