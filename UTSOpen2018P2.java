



import java.util.*;
import java.io.*;

public class UTSOpen2018P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int a[][] = new int[3][3], ans = Integer.MIN_VALUE, sum = 0; 
        for (int i = 0;i<3;i++) {
            for (int j = 0;j<3;j++) {
                a[i][j] = Integer.parseInt(next());
            }
        }
        
        for (int i=0;i<3;i++) {
            if (i == 0) {
                if (a[0][2] == a[1][0]) sum += a[2][i];
            } else {
                if (a[1][i] == a[0][i-1]) {
                    sum += a[2][i];
                }
            }
            if (a[2][i] > sum && sum < 0) {
                ans = Math.max(ans, a[2][i]);
            } else {
                ans = Math.max(sum, ans);

            }
            
        }
        System.out.println(ans);

        
        
        
    }
 
    
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


