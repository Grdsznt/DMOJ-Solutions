import java.util.*;
import java.io.*;

public class SAC2021CodeChallengeP3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), P = Integer.parseInt(next());
        String st[][] = new String[N][2];
        for (int i = 0; i < N; i++) {
            String[] s = br.readLine().trim().split(" ");
            st[i][0] = s[0];
            st[i][1] = Long.toString((int) (Math.floor(4 * Math.sqrt(Integer.parseInt(s[1])) + 3 * Math.pow(Integer.parseInt(s[2]), P) - 4 * Integer.parseInt(s[3]))));
        }
        Arrays.sort(st, new Comparator<String[]>() {
            @Override
            public int compare(String[] o1, String[] o2) {
                return o1[0].compareTo(o2[0]);
            }
        });
        System.out.println(st[st[0].length - 1][0] + " " + st[st[0].length - 1][1]);
        System.out.println(st[0][0] + " " + st[0][1]);
        

    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
