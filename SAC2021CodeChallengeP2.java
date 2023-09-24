import java.util.*;

import java.io.*;

public class SAC2021CodeChallengeP2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), K = Integer.parseInt(next()); long a[] = new long[N], ans = 0; 
        for (int i = 0;i<N;i++) {
            a[i] = Long.parseLong(next());
        }
        
        Arrays.sort(a);
        for (int i = 0;i<K;i++) {
            ans += a[a.length-1-i];
        }
        System.out.println(ans);
        
    }
    
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }   
}


