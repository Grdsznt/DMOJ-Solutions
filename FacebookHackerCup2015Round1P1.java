


import java.util.*;
import java.io.*;

public class FacebookHackerCup2015Round1P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] primes;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int T = Integer.parseInt(next()), num = 1; primes = new int[10000001];
        sieve(10000001);
        for (int i = 0;i<T;i++) {
            int A = Integer.parseInt(next()), B = Integer.parseInt(next()), primacity = Integer.parseInt(next()), ans = 0;
            for (int j = A;j<=B;j++) {
                if (primes[j] == primacity) ans++;
            }
            System.out.println("Case #" + num + ": "+ ans); ++num;
        }
        //how to determine primacity? We loop through every prime number and see if the modulus is 0 or not
    }

    
    static void sieve(int n) {
        int i,j;
        
        for (i=2;i<n;i++){
            if (primes[i] == 0) {
                for (j=i+i;j<n;j+=i) primes[j]++;
            }
        }
        for (i=2;i<n;i++)  if (primes[i] == 0) primes[i]++;
    }
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}



