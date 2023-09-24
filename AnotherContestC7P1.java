import java.io.*;
import java.util.*;

public class AnotherContestC7P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int T = Integer.parseInt(next());
        for (int i = 0;i<T;i++) {
            long n = Long.parseLong(next());
            if (n == 2) {
                System.out.println(2);
            } else {
                System.out.format("%d%n", n-1);
            }
        }
    }
    static String next () throws IOException { 
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}