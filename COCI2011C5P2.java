import java.util.*;
import java.io.*;

public class COCI2011C5P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), M = Integer.parseInt(next()), a[] = new int[N], lo = 0, hi, ans = 0;
        for (int i = 1; i <= N; i++) {
            a[i] = Integer.parseInt(next());
        }
        Arrays.sort(a); hi = a[a.length-1];

        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (check(mid)) {
                ans = mid;
                lo = mid+1;
            }else {
                hi = mid-1;
            }
        }
        
        System.out.println(ans);
        
        

    }

    static int check(int n) {
        if ()
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }


}
