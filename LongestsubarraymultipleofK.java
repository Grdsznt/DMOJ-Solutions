import java.util.*;
import java.io.*;
public class LongestsubarraymultipleofK {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
 
    public static void main(String[] args) throws IOException{
        int n = readInt(), k = readInt(), sum = 0, ans = -1;
        int[] leftPointer = new int[k+1];
        Arrays.fill(leftPointer, -1);
        leftPointer[0] = 0;
        for (int i = 0; i<=n; i++) {
            sum = (sum + readInt()) % k;
            if(leftPointer[sum] != -1) ans = Math.max(ans, i - leftPointer[sum]);
            else leftPointer[sum] = i;
        }
        System.out.println(ans);
    }
 
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }  
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}