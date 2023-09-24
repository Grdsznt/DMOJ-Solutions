



import java.util.*;
import java.io.*;

public class MaxAngerContestS2P3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int Q = Integer.parseInt(next()), N = Integer.parseInt(next()), a[] = new int[N+1];
        for (int i = 1;i<=N;i++) {
            a[i] = a[i-1] + Integer.parseInt(next());
        }
        for (int i = 0;i<Q;i++) {
            String s = next(); int L = Integer.parseInt(next()), S = Integer.parseInt(next());
            int target = S+a[L-1]; 
            int indx = Arrays.binarySearch(a, target);
            if (indx < 0) {indx = -indx - 1;}
            if (indx > a.length-1) {System.out.println(N);}
            else System.out.println(indx);

        }
        
        
        
    }
 
    
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


