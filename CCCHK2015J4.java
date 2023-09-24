import java.util.*;
import java.io.*;

public class CCCHK2015J4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException{
        int L = Integer.parseInt(next()), N = Integer.parseInt(next()), da[] = new int[L+1],  max = 0,  sum = 0;
        boolean stop = false;
        // use difference array
        for (int i = 0;i<N;i++) {
            int s = Integer.parseInt(next()), t = Integer.parseInt(next());
            da[s]++; da[t]--;
        } 
        for (int i = 1;i<=L;i++) {
            da[i] = da[i-1] + da[i];
        }
        for (int i = 0;i<L+1;i++) {
            if (da[i] == 0 && i != L) {++sum; stop = false;}
            else if (stop == true) {sum = 0;}
            else stop = true;
            max = Math.max(sum, max);
        }
        
        System.out.println(max);

       
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}