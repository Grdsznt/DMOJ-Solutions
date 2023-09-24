
import java.util.*;
import java.io.*;

public class DMOPC2019C1P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String s = "Good writing is good ", t = " writing is good ", u = " is good writing.", f0 = "Good writing is good writing is good writing.";
    public static void main(String[] args) throws NumberFormatException, IOException {
        int q = Integer.parseInt(next());

        long[] l = new long[31];
        l[0] = f0.length();
        for (int i = 1;i<31;i++) {
            l[i] = s.length() + l[i-1] + t.length() + l[i-1] + u.length();
        }
        
        for(int i = 0;i<q;i++) {
            int n = Integer.parseInt(next()), k = Integer.parseInt(next());
            if (k > l[n]) System.out.println(".");
            else {
                System.out.println(func(n, k-1, l));
            }
        }
        
        
    }
    static char func(int n, int k, long [] l) {
        if (n == 0) return f0.charAt(k);
        if (k < s.length()) {return s.charAt(k);}
        k -= s.length();
        if (k < l[n-1]) {return func(n-1, k, l);}
        k -= l[n-1];
        if (k < t.length()) {return t.charAt(k);}
        k -= t.length();
        if (k < l[n-1]) {return func(n-1, k, l);}
        k -= l[n-1];
        return u.charAt(k);

    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}


