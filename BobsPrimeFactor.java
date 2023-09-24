import java.util.*;
import java.io.*;

public class BobsPrimeFactor {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), a[] = new int[N], maxFactor = 0, indx = 0, element;
        for (int i = 0;i<N;i++) {
            a[i] = Integer.parseInt(next());
        }
        for (int i = 0;i<N;i++) {
            element = a[i];
            for (int j = 2;j <= Math.sqrt(element);j++) {
                while (element % j == 0) {
                    element /= j;
                    if (j > maxFactor) {
                        maxFactor = j;
                        indx = i;
                    }
                    
                }
            }
            if (element != 1) {
                if (element > maxFactor) {
                    maxFactor = element;
                    indx = i;
                }
            }
            
        }
        System.out.println(a[indx]);

        

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

