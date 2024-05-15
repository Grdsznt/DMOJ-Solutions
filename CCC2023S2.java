import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CCC2023S2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException{
        int N = Integer.parseInt(next()), a[] = new int[N];
        for (int i = 0;i<N;i++) {
            a[i] = Integer.parseInt(next());
        }
        for (int len = 1;len<=N;len++) { // loop through all lengths of crop
            int ans = Integer.MAX_VALUE;
            for (int st = 0;st<=N-len;st++) {
                int end = st+len-1, sum = 0;
                for (int k = 0;k<=(end-st)/2;k++) {
                    sum += Math.abs(a[st+k] - a[end-k]);
                } 
                ans = Math.min(ans, sum);
            }
            System.out.print(len == N ? ans : ans + " ");
        }
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}


