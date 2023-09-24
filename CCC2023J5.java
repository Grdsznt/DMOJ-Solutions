import java.io.*;
import java.util.*;

public class CCC2023J5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int ways = 0;
    public static void main(String[] args) throws IOException {
        String input = br.readLine().trim();
        int R = br.read(), C = br.read();
        
        String[][] whole = new String[100][100];
        for (int i = 0;i<R;i++) {
            String[] g = br.readLine().trim().split(" ");
            for (int j = 0;j<g.length;j++) {
                whole[i][j] = g[j];
            }
        }
        int[][] dir = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1} , {1, 0} , {1, -1} , {0, -1}, {-1, -1}};
        for (int j = 0;j<R;j++) {
            for (int k = 0;k<C;k++) {
                if (whole[j][k] == Character.toString(input.charAt(0))) {
                    for (int l = 0;l<8;l++) {
                        int ni = j + dir[l][0];
                        int nj = k + dir[l][0];
                        if (0<=ni && ni < R && 0 <= nj && nj<C && whole[ni][nj].equals(input.charAt(1))) {
                            func(ni, nj, l, 2, false, input, dir, R, C, whole);
                        }
                    }
                }
            }
        }
        System.out.println(ways);

        
        
        
    }
    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
    static void func(int r, int c, int k, int index, boolean turned, String word, int[][] dir, int R, int C, String[][] whole) {
        if (index == word.length()) {
            ways++;
            return;
        }
        for (int i = k-2;i<k+3;i += 2) {
            int newk = (i + 8) % 8;
            int newr = r + dir[k][0], newc = c + dir[k][1];
            if (0 <= newr && newr < R && 0 <= newc && newc < C && whole[newr][newc].equals(word.charAt(index)) && (newk == k || !turned)){
                func(r, c, k, index, turned, word, dir, R, C, whole); func(newr, newc, newk, index+1, turned || newk != k, word, dir, R, C, whole);
            }
        }
    }
}