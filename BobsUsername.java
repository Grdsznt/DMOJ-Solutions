import java.util.*;
import java.io.*;

public class BobsUsername {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int k = Integer.parseInt(next()), n = Integer.parseInt(next());
        long ans = (long) Math.pow(n, k);

        System.out.println(ans);

    }

    

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }


}


class node {
    int number;
    node left;
    node right;

    node(int number) {
        this.number = number;
        this.right = null;
        this.left = null;
    }
}

