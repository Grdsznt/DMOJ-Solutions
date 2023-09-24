import java.util.*;
import java.io.*;

public class BobsPayTrip {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), a[] = new int[N], total = 0, dist = 0;
        
        for (int i = 0;i<N;i++) {
            a[i] = Integer.parseInt(next());
        }

        for (int i = 0;i<N;i++) {
            if (a[i] > 0) {
                total += a[i];
                dist += i+1;
            }
        }

        

        

    }

    // static boolean isPrime(int n) {
    //     for (int i = 2;i*i<=n;i++) {
            
    //     }
    // }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }


}

