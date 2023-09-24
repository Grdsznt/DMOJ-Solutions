import java.util.*;


import java.io.*;

public class UCCCodingCompetition2021P3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), x = Integer.parseInt(next()), y = Integer.parseInt(next()), R = Integer.parseInt(next()), diffA[] = new int[N+2];
        long ans = 0;
        for (int i = 0;i<R;i++) {
            diffA[Integer.parseInt(next())]++; diffA[Integer.parseInt(next())+1]--;
        }
        for (int i = 1;i<=N;i++) {
            diffA[i] = diffA[i] + diffA[i-1];
        } 
        for (int i = x;i<=y;i++) {
            ans += diffA[i];
        }
        System.out.println(ans);
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }   
}


