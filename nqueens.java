import java.util.*;
import java.io.*;


public class nqueens {
    static int positioninrow[] = new int [30];
    static boolean col[] = new boolean[30], lft[] = new boolean [30], rite[] =  new boolean [30];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st; 
    
    static void solve(int row, int n) {
        if (row == n) {
            for (int i = 0;i<n;i++) {
                for (int j = 0;j<n;j++) {
                    if (j == positioninrow[i]) { System.out.print('Q');}
                    else { System.out.print('.'); }
                }
                System.out.print('\n');

            }
            return;
        }
        for (int i = 0;i<n;i++) {
            if (!col[i] && !lft[row+i] && !rite[row-i+n-1]) {
                positioninrow[row] = i;  
                col[i] = lft[row+1] = rite[row-i-1+n] = true;
                solve(row+1, n);
                col[i] = lft[row+1] = rite[row-i-1+n] = false;
            }
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {
        int n = Integer.parseInt(next());
        solve(0, n);
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
