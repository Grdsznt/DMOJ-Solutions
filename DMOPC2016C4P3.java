import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.SortedSet;
import java.util.StringTokenizer;



public class DMOPC2016C4P3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args)  throws IOException{
        TreeSet<Pair> ca = new Treeset<Pair>();
        int N = Integer.parseInt(next()), S = Integer.parseInt(next()), d[] = new int[10003];
        for (int i = 0;i<N;i++) {
            d[i] = Integer.parseInt(next());
        }
        for (int i = 0;i<S;i++) {
            int s = Integer.parseInt(next()), a = Integer.parseInt(next());
        }
        int Q = Integer.parseInt(next());
        for (int i = 0;i<Q;i++) {
            String[] s = br.readLine().split(" ");
            if (s[0] == "A") {

            }else if (s[0] == "S") {
                
            }else if (s[0] == "E") {

            }else {

            }
        }
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    public static class pair  {
        public int x, y;
        pair (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
