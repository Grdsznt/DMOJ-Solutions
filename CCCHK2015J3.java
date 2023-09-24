import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
public class CCCHK2015J3 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), M = Integer.parseInt(next()), sol = 0;
        boolean[] row = new boolean[N], col = new boolean[N], ld = new boolean[2*N-1], rd = new boolean[2*N-1];
        for (int i = 0;i<M;i++) {
            int x = Integer.parseInt(next())-1, y = Integer.parseInt(next())-1;
            row[x] = col[y] = ld[x+y] = rd [x+N-1-y] = true;  

        }

        for (int j = 0;j<N;j++) {
            for (int k = 0;k<N;k++) {
                if (row[j] == false && col[k] == false && ld[j+k] == false && rd[j+N-1-k] == false) {
                    ++sol;
                } 
            }
        }
        System.out.println(sol);
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
