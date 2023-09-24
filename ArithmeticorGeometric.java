import java.util.*;


import java.io.*;

public class ArithmeticorGeometric {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int T = Integer.parseInt(next());
        for (int i = 0;i<T;i++) {
            long a1 = Integer.parseInt(next()), a2 = Integer.parseInt(next()), a3 = Integer.parseInt(next()), k = Integer.parseInt(next());
            long ans = a3;

            if ((a2/a1) % 1000000007 == (a3/a2) % 1000000007) {
                long commonRatio = a2/a1;
                ans = (a3)* (long) Math.pow(commonRatio, k-1) % 1000000007;
                
            } else {
                long d = a2-a1;
                ans = (ans+d) % 1000000007 * (k-3) % 1000000007;
                
            }
            System.out.println(ans);
        }
        
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }   
}


