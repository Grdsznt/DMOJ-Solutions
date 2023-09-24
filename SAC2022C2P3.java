import java.util.*;
import java.io.*;
public class SAC2022C2P3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int n = Integer.parseInt(next()), a[] = new int [n];
        for (int i = 0;i<n;i++) {
            a[i] = Integer.parseInt(next());
        }
        Arrays.sort(a);

        System.out.println(a[n/2]);

    }
    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}
