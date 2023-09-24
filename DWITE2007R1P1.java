
import java.util.*;
import java.io.*;

public class DWITE2007R1P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int n = Integer.parseInt(next()); 
        if (n < 0) {
            System.out.println("not"); return;
        }
        if (n == 1 || n == 0) {
            System.out.println("not"); return;
        } else {
            System.out.println(isPrime(n) ? "prime" : "not");
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


