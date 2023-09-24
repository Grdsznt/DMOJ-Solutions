



import java.util.*;
import java.io.*;

public class DWITE2011R4P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int Y = Integer.parseInt(next());
        for (int i = 2;i<=Math.sqrt(Y);i++) {
            while (Y % i == 0) { 
                System.out.println(i); Y /= i;
            }
        }
        if (Y != 1) System.out.println(Y);
    }

 
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


