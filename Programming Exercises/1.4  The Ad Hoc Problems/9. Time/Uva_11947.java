import java.io.FileInputStream;
import java.io.PrintStream;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;

class UVa_11947 {
	
	final Date AQUARIUS = new GregorianCalendar(1970, 0, 21).getTime();
	final Date PISCES = new GregorianCalendar(1970, 1, 20).getTime();
	final Date ARIES = new GregorianCalendar(1970, 2, 21).getTime();
	final Date TAURUS = new GregorianCalendar(1970, 3, 21).getTime();
	final Date GEMINI = new GregorianCalendar(1970, 4, 22).getTime();
	final Date CANCER = new GregorianCalendar(1970, 5, 22).getTime();
	final Date LEO = new GregorianCalendar(1970, 6, 23).getTime();
	final Date VIRGO = new GregorianCalendar(1970, 7, 22).getTime();
	final Date LIBRA = new GregorianCalendar(1970, 8, 24).getTime();
	final Date SCORPIO = new GregorianCalendar(1970, 9, 24).getTime();
	final Date SAGITTARIUS = new GregorianCalendar(1970, 10, 23).getTime();
	final Date CAPRICORN = new GregorianCalendar(1970, 11, 23).getTime();

	void start(Scanner scan) throws ParseException {
		SimpleDateFormat in = new SimpleDateFormat("MMddyyyy");
		SimpleDateFormat out = new SimpleDateFormat("MM/dd/yyyy");
		int tc = scan.nextInt();
		scan.nextLine();
		for (int i = 1; i <= tc; i++) {
			String dateString = scan.nextLine();
			Date date = in.parse(dateString);
			
			GregorianCalendar calendar = new GregorianCalendar();
			calendar.setTime(date);
			calendar.add(Calendar.WEEK_OF_MONTH, 40);
			
			System.out.print(i + " " + out.format(calendar.getTime()) + " ");

			calendar.set(Calendar.YEAR, 1970);
			Date birthDate = calendar.getTime();
			String sign;
			if (birthDate.before(AQUARIUS))
				sign = "capricorn";
			else if (birthDate.before(PISCES))
				sign = "aquarius";
			else if (birthDate.before(ARIES))
				sign = "pisces";
			else if (birthDate.before(TAURUS))
				sign = "aries";
			else if (birthDate.before(GEMINI))
				sign = "taurus";
			else if (birthDate.before(CANCER))
				sign = "gemini";
			else if (birthDate.before(LEO))
				sign = "cancer";
			else if (birthDate.before(VIRGO))
				sign = "leo";
			else if (birthDate.before(LIBRA))
				sign = "virgo";
			else if (birthDate.before(SCORPIO))
				sign = "libra";
			else if (birthDate.before(SAGITTARIUS))
				sign = "scorpio";
			else if (birthDate.before(CAPRICORN))
				sign = "sagittarius";
			else
				sign = "capricorn";
			
			System.out.println(sign);
		}
	}
}
