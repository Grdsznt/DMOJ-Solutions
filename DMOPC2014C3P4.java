



import java.util.*;
import java.io.*;

public class DMOPC2014C3P4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int[] factors = new int[100001];
        for (int j = 1;j<=100000;j++) {
            
            for (int k = 1;k<=(int)Math.sqrt(j);k++) {
                
                if (j % k == 0 && k*k != j) {factors[j] += 2;}
                else if (k*k == j) {factors[j]++;}
            }
        }
        
        for (int i = Integer.parseInt(next()); i > 0;i--) {
            int K = Integer.parseInt(next()), A = Integer.parseInt(next()), B = Integer.parseInt(next()), ans = 0;
            
            for (int j = A;j<=B;j++) {
                if ((factors[j]) == K) ans++;
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


