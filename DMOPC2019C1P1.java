import java.io.*;
import java.util.*;

public class DMOPC2019C1P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(next());
        for (int i = 0;i<N;i++) {
            long n = Long.parseLong(next()), a = Long.parseLong(next()), b = Long.parseLong(next()), t = Long.parseLong(next());
            long correct = -1, sum = 0, hi = n, lo = 0;
            /*binary search always checking the sum
            */
            while (hi-lo > 1) {
                long middle = (long) Math.floor((hi+lo)/2);
                sum = (a*middle) - b*(n-middle);
                if (sum >= t) {
                    hi = middle;
                    correct = middle;
                } else {
                    lo = middle;
                } 
                    
            } 
            if (correct == -1 && (a*hi) - b*(n-hi) >= t) {
                correct = hi;
            } 
            System.out.println(correct);
                // long middle = (long) Math.floor((hi+lo)/2);
                // sum = (a*middle) - b*(n-middle);
                // if (sum >= t) 

            // }
            // for (int j = 0;j<=n;j++) {
            //     sum = (a*correct) - b*(n-correct);
            //     if (sum >= t) break; 
            //     correct++; 
            // }
            // System.out.println(sum >= t ? correct : -1);
        }
    }

    // static boolean solve(int n, int a, int b, int t, int sum, int correct, int question ) {
    //     if (question >= n) {
    //         if (sum + (n - correct) * a >= t) {
    //             return true;
    //         } else  {
    //             return false;
    //         }
            
    //     }
    //     if (sum >= t) {
    //         min = Math.min(correct, min);
    //         return true;
    //     }

    //     sum = (sum + a*correct) - b*(n-correct);

    //     if (solve(n, a, b, t, sum, correct+1, question+1)) {
    //         return true;
    //     } //choose

    //     if (solve(n, a, b, t, sum, correct, question+1)) {
    //         return true;
    //     } // don't choose

        
    //     return false;
    // }

    static String next () throws IOException { 
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}