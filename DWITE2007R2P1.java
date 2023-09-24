



import java.util.*;
import java.io.*;

public class DWITE2007R2P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        for (int i = 0;i<5;i++) {
            int n = Integer.parseInt(next());
            System.out.println(semiPrime(n) ? "semiprime" : "not");
        }

        
    }

    static boolean semiPrime(int n) {
        List<Integer> al = new ArrayList<>();
        for (int i = 2;i*i<=n;i++) {
            while (n % i == 0) {
                al.add(i);
                n /= i;
            }
        }
        if (n != 1) {al.add(n);}
        if (al.size() == 2) return true;
        else return false;
    }



 
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


