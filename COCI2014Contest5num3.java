import java.util.*;
import java.io.*;
public class COCI2014Contest5num3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt(), k = readInt();
        int[] row = new int[(int)1e5], col = new int[(int)1e5], ld = new int[2*(int)1e5-1], rd = new int[2*(int)1e5-1];

        for (int i = 1;i<=n;i++) {
            int r = readInt()-1, c = readInt()-1;
            row[r]++; col[c]++; ld[r+c]++; rd[r+(int)1e5-1-c]++;
            if (row[r] == k || col[c] == k || ld[r+c] == k || rd[r + (int)1e5-1-c] == k) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }  
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}
