import java.util.Scanner;

class E_1_3_2 {
	
	Scanner scan;
	
	public E_1_3_2(Scanner scan) {
		this.scan = scan;
	}
	
	/**
	 * 3
	 * 1 2
	 * 5 7
	 * 6 3
	 */
	public void inputFirstLine() {
		int tc = scan.nextInt();
		while (tc-- > 0) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			System.out.println(a + b);
		}
	}

	/**
	 * 1 2
	 * 5 7
	 * 6 3
	 * 0 0
	 */
	public void inputSpecialValues() {
		int a = scan.nextInt();
		int b = scan.nextInt();
		while (a != 0 || b != 0) {
			System.out.println(a + b);
			a = scan.nextInt();
			b = scan.nextInt();
		}
	}
	
	/**
	 * 1 2
	 * 5 7
	 * 6 3
	 */
	public void inputEof() {
		while (scan.hasNextInt()) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			System.out.println(a + b);
		}
	}
	
	/**
	 * Case 1: 3
	 * 
	 * Case 2: 12
	 * 
	 * Case 3: 9
	 * 
	 */
	public void outputBlankLines1() {
		int tc = 1;
		while (scan.hasNextInt()) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			System.out.print("Case " + (tc++) + ": " + (a + b) + "\n\n");
		}
	}
	
	/**
	 * Case 1: 3
	 * 
	 * Case 2: 12
	 * 
	 * Case 3: 9
	 */
	public void outputBlankLines2() {
		int tc = 1;
		while (scan.hasNextInt()) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			if (tc > 1)
				System.out.println();
			System.out.print("Case " + (tc++) + ": " + (a + b) + "\n");
		}
	}
	
	/**
	 * 1 1
	 * 2 3 4
	 * 3 8 1 1
	 * 4 7 2 9 3
	 * 5 1 1 1 1 1
	 */
	public void variableInput() {
		while (scan.hasNextInt()) {
			int n = scan.nextInt();
			int ans = 0;
			while (n-- > 0) {
				int num = scan.nextInt();
				ans += num;
			}
			System.out.println(ans);
		}
	}
}
