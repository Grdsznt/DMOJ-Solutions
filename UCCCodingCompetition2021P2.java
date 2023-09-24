import java.util.*;
import java.io.*;

public class UCCCodingCompetition2021P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), sum = 0, ans = 0;
        for (int i = 0;i<N;i++) {
            int ai = Integer.parseInt(next());
            if (ai % 2 != 1) {
                sum += ai;
            } else {
                sum = 0;
            }
            ans = Math.max(sum, ans);
        } 
        System.out.println(ans);
          
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }   
}


