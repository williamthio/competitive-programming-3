import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Scanner;

class UVa_00893 {
	
	public void start(Scanner scan) {
		while (true) {
			int predict = scan.nextInt();
			int dayOfMonth = scan.nextInt();
			int month = scan.nextInt();
			int year = scan.nextInt();
			
			if (predict == 0 && dayOfMonth == 0 && month == 0 && year == 0)
				break;
			
			GregorianCalendar calendar = new GregorianCalendar(year,
					month - 1, dayOfMonth);
			calendar.add(Calendar.DAY_OF_MONTH, predict);
			System.out.println(calendar.get(Calendar.DAY_OF_MONTH) + " " +
					(calendar.get(Calendar.MONTH) + 1) + " " +
					calendar.get(Calendar.YEAR));
		}
	}
}
