// import java.util.*;
// import java.io.*;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
public class DMOPC2018C6P0 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException, NumberFormatException {
        int[] a = new int[3];
        a[0] = Integer.parseInt(next()); a[1] = Integer.parseInt(next()); a[2] = Integer.parseInt(next());
        Boolean b = false;
        for (int i = 0;i<3;i++) {
            if (a[i] == 0) {
                b = true;
                for (int j = 0;j<3;j++) {
                    if (a[j] != 0 && a[a[j]-1] == j+1) {
                        b = false;
                        break;
                    }
                }
            }
        }
        

        System.out.println(b ? "YES": "NO");
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}