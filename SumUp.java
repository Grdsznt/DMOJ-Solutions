import java.util.*;
import java.io.*;

public class SumUp {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), a[] = new int[N+1];
        long K = Long.parseLong(next());
        for (int i = 0;i<N;i++) {
            a[i] = Integer.parseInt(next());
        }
        int sum = 0; 
        for (int i = 0;i<N;i++) {
            sum += a[i];
        }
        if (sum < K) {System.out.println(-1); return;}
        Arrays.sort(a); sum = 0;
        for (int i = 0;i<N;i++) {
            sum += a[a.length-1-i];
            if (sum >= K) {
                System.out.println(i+1); return;
            } 
        }
        

        

    }

    

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }


}

