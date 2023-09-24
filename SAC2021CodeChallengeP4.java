import java.util.*;
import java.io.*;

public class SAC2021CodeChallengeP4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), Q = Integer.parseInt(next()), psa[] = new int[N+1];
        for (int i = 1; i <= N; i++) {
            psa[i] = psa[i-1] + Integer.parseInt(next());
        }
        for (int i = 0;i<Q;i++) {
            int L = Integer.parseInt(next()), R = Integer.parseInt(next());
            System.out.println((int) Math.floor((psa[R] - psa[L-1]) / (R-L+1)));
        }
        
        

    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
