import java.util.*;
import java.io.*;

public class YetAnotherContest2P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int T = Integer.parseInt(next());
        
        for (int i = 0;i<T;i++) {
            Double A = Double.parseDouble(next()), B = Double.parseDouble(next()), C = Double.parseDouble(next()), D = Double.parseDouble(next());
            
            System.out.println(((B/A < D/C || B/A > D/C) && !( A > B && C > D )) ? "YES" : "NO");
            
        }
       
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
