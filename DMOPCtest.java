import java.io.*;
import java.util.*;

public class DMOPCtest {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(next()), D = Integer.parseInt(next());
        int[] a = new int[N];
        int[] prefixSum = new int[N];
        a[0] = Integer.parseInt(next());
        prefixSum[0] = a[0];

        for (int i = 1; i < N; i++) {
            a[i] = Integer.parseInt(next());
            prefixSum[i] = prefixSum[i-1] + a[i];
        }

        for (int i = 0; i < D; i++) {
            int n = Integer.parseInt(next());
            int sumr = prefixSum[N-1] - prefixSum[n-1];
            int suml = prefixSum[n-1];

            if (sumr > suml) {
                System.out.println(sumr);
                N = n;
            } else {
                System.out.println(suml);
                int[] temp = new int[N-n];
                System.arraycopy(a, n, temp, 0, N-n);
                System.arraycopy(temp, 0, a, n, N-n);

                prefixSum[N-1] = a[N-1];
                for (int j = N-2; j >= n-1; j--) {
                    prefixSum[j] = prefixSum[j+1] + a[j];
                }
                N = N - n;
            }
        }
    }

    static String next () throws IOException { 
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
