import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CCC2021S3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int N = Integer.parseInt(next()), K = Integer.parseInt(next()), cnt = 0; 
        // int[][]art = new int[M+1][N+1];
        int[] row = new int[M+1], col = new int[N+1];
        for (int i = 0;i<K;i++) {
            String s = next();
            if (s.contains("C")) {
                int c = Integer.parseInt(next());
                col[c]++;
                // for (int j = 1;j<=M;j++) {
                //     if (art[j][c] == 0) {
                //         art[j][c] = 1;
                //     } else {
                //         art[j][c] = 0;
                //     }
                // }
            } else {
                int r = Integer.parseInt(next()); row[r]++;
                // for (int j = 1;j<=N;j++) {
                //     if (art[r][j] == 0) {
                //         art[r][j] = 1;
                //     } else {
                //         art[r][j] = 0;
                //     }
                // }
            }
        }
        // if row[r] is even and col[c] is even, then it's black
        // if row[r] is even and col[c] is odd, then it's gold
        // if row[r] is odd an col[c] is odd, then it's black
        // if row[r] is odd and col[c] is even, then it's goldl
        for (int i = 1;i<=M;i++) {
            for (int j = 1;j<=N;j++) {
                if (!(row[i] % 2 == col[j] % 2)) {
                    cnt++;
                }
            }
        }

        System.out.println(cnt);

    }

    

    static String next() throws IOException{
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
