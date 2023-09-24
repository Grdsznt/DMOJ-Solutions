import java.util.*;
import java.io.*;
public class PalindromicPartititons {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next());
        List<Integer> al = new ArrayList<>();
        System.out.println(countParts(N, al));


    }
    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }

    static int countParts(int n, List<Integer> part) {
        if (n == 0) {
            int length = part.size();
            boolean isPal = true;
            for (int i = 0;i<length/2;i++) {
                if (part.get(i) != part.get(length-i-1)) {
                    isPal = false;
                    break;
                }
            }
            if (isPal) {
                return 1;
            } else {
                return 0;
            }
        }
        int count = 0;
        int element = part.isEmpty() ? 1 : part.get(part.size()-1);
        for (int j = element;j<=n;j++) {
            part.add(j);
            count += countParts(n-j, part);
            part.remove(part.size()-1);
        }
        return count;
    }
}
