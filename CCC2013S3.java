import java.util.*;
import java.io.*;


public class CCC2013S3 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[][] teams = new int[4][2];
    public static void main(String[] args) throws NumberFormatException, IOException {
        int team = Integer.parseInt(next()), gamesAlr = Integer.parseInt(next());
        for (int i = 0;i<gamesAlr;i++) {
            String[] input = br.readLine().trim().split(" ");

            if (Integer.parseInt(input[4]) > Integer.parseInt(input[3])) {
                teams[Integer.parseInt(input[0])][1] += 3;
            } else if (input[4] == input[3]) {
                ++teams[Integer.parseInt(input[1])][1]; ++teams[Integer.parseInt(input[0])][1];
            } else {
                teams[Integer.parseInt(input[1])][1] += 3;
            }
        }
        
    }

    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}