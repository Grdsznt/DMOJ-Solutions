import java.util.*;

import java.io.*;

public class SAC2021CodeChallengeP1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int mod = 1000000007;
    public static void main(String[] args) throws NumberFormatException, IOException {
         System.out.println(Long.parseLong(next())/40);
        
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }   
}


