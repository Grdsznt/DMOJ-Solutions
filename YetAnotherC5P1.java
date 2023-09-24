import java.util.*;
import java.io.*;

public class YetAnotherC5P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()); long K = Long.parseLong(next()); int X = Integer.parseInt(next());
        
        long pw = 1;
         
        for (int i = 0;i<N-1;i++) {
            System.out.print(K-1 + " ");
            pw = pw*2%K;
        }  
        pw = (pw-1+K) % K * (K-1) % K;
        System.out.print( (X-pw + K ) % K + "\n");
          
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }   
}


