import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    void start(BufferedReader br) throws Exception {
        String line = null;
        while ((line = br.readLine()) != null) {
            ArrayList<BigInteger> nums = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(line);

            if (!st.hasMoreTokens())
                continue;

            String token = st.nextToken();
            while (!token.equals("-999999")) {
                nums.add(new BigInteger(token));
                token = st.nextToken();
            }

            if (nums.isEmpty())
                continue;

            boolean haveZero = false;
            for (int i = 1; i < nums.size(); i++) {
                if (nums.get(i).equals(BigInteger.ZERO) ||
                        nums.get(i - 1).equals(BigInteger.ZERO)) {
                    haveZero = true;
                    continue;
                }
                nums.set(i, nums.get(i).multiply(nums.get(i - 1)));
            }

            BigInteger ans = null;
            for (int i = 0; i < nums.size(); i++) {
                if (nums.get(i).equals(BigInteger.ZERO))
                    continue;
                for (int j = i; j < nums.size(); j++) {
                    if (nums.get(j).equals(BigInteger.ZERO))
                        break;
                    BigInteger v = nums.get(j);
                    if (i > 0 && !nums.get(i - 1).equals(BigInteger.ZERO))
                        v = v.divide(nums.get(i - 1));
                    if (ans == null || ans.compareTo(v) < 0)
                        ans = v;
                }
            }

            if (ans == null)
                ans = BigInteger.ZERO;

            if (haveZero) {
                if (ans.compareTo(BigInteger.ZERO) < 0)
                    System.out.println("0");
                else
                    System.out.println(ans);
            } else {
                System.out.println(ans);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        new Main().start(br);
        br.close();
    }
}

