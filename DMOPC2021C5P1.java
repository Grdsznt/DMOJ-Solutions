
import java.util.*;
import java.io.*;

public class DMOPC2021C5P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int n = Integer.parseInt(next());
        int[] a = new int[n];
        
        if (n < 5 && n != 1) {System.out.println(-1); return;}
        else if (n == 1) {System.out.println(1); return;} 
        else {
            int st = 0,  end = n;
            
            for (int i = 1;i<=n;i++) {
                if (i != 4 && i != 5) {
                    if (i % 2 == 0) a[st++] = i;
                    else a[--end] = i;
                }
            }
            a[n/2-1] = 4; a[n/2] = 5;
            
            for (int i = 0;i<n;i++) {System.out.print(i+1 != n ? a[i] + " " : a[i]);}
            System.out.print("\n");
        }
        
    }


    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}


