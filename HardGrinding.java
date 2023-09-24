import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class HardGrinding {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        
        int n = Integer.parseInt(next()), max = (int)1e7;

        // init array with 2 more cells than needed because you need r+1 and you don't use index 0
        int[] diffArr = new int[max+2];

        // Doing indice updates
        for (int i = 1; i<=n;i++) {
            int l = Integer.parseInt(next()), r = Integer.parseInt(next());
            // ending is not included therefore r and not r+1
            diffArr[l] += 1; diffArr[r] -= 1;

        }
        int result = 0;

        // get psa(dif(A)) to get the range update vals
        for (int j = 1; j<diffArr.length;j++) {
            diffArr[j] += diffArr[j-1];

            // Take the max overlap
            result = Math.max(result, diffArr[j]);
        }
        System.out.println(result);
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
