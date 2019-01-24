import java.io.FileInputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

class UVa_11947 {

	void start(Scanner scan) {
		int[] nums = new int[101];
		BigInteger[] sums = new BigInteger[100];
		
		while (scan.hasNextInt()) {
			int n = 0;
			int num = scan.nextInt();
			
			while (num != -999999) {
				nums[n++] = num;
				num = scan.nextInt();
			}
			
			for (int i = 0; i < n; i++)
				sums[i] = new BigInteger(String.valueOf(nums[i]));
			
			boolean haveZero = false;
			for (int i = 1; i < n; i++) {
				if (nums[i] == 0 || nums[i - 1] == 0) {
					haveZero = true;
					continue;
				}
				sums[i] = sums[i].multiply(sums[i - 1]);
			}
			
			BigInteger ans = null;
			for (int i = 0; i < n; i++) {
				if (nums[i] == 0)
					continue;
				for (int j = i; j < n; j++) {
					if (nums[j] == 0)
						break;
					BigInteger v = new BigInteger(sums[j].toString());
					if (i > 0 && nums[i - 1] != 0)
						v = v.divide(sums[i - 1]);
					if (ans == null || ans.compareTo(v) < 0)
						ans = v;
				}
			}
			
			if (ans == null)
				ans = BigInteger.ZERO;
			
			if (haveZero)
				System.out.println(ans.compareTo(BigInteger.ZERO) < 0 ? "0" : ans.toString());
			else
				System.out.println(ans.toString());
		}
	}
	
	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(System.in);
		new Uva_11947().start(scan);
		scan.close();
	}
}
