import java.util.*;
import java.io.*;

public class CCC1997S3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int n = Integer.parseInt(next()), t = Integer.parseInt(next());
        for (int i = 0;i<n;i++) {
            int undftd = t, onelss = 0, elim = 0, cnt = 0;
            while (true) {
                System.out.println("Round " + cnt + ": " + undftd + " undefeated, " + onelss + " one-loss, " + elim + " eliminated");
                if (undftd == 0 && onelss == 1) break;
                if (undftd == 1 && onelss == 1) { undftd = 0; onelss = 2;}
                else {
                    elim += Math.floor(onelss/2);
                    onelss = (int) (onelss - Math.floor(onelss/2) + Math.floor(undftd/2));
                    undftd = (int) Math.floor(undftd/2);
                }
                ++cnt;
            }
            System.out.println("There are " + cnt + " rounds.");
            if (i != n-1) System.out.println("\n");
        }
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}

