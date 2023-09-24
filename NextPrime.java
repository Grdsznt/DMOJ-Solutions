
import java.util.*;
import java.io.*;

public class NextPrime {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        long n = Integer.parseInt(next()); 
        if (n == 1) {
            System.out.println(2); return;
        } 
        for(long i = n;i<2100000000;i++) {
            if (isPrime(i)) {
                System.out.println(i);
                break;
            }
        }
    }
    
    static boolean isPrime(long n) {
        for(int i = 2;i*i<=n;i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}


