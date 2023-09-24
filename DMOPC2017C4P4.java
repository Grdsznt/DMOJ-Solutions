import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
import java.util.*;

public class DMOPC2017C4P4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int max = (int) (1e6+2);
    static boolean[] guard = new boolean[max], fst = new boolean[max];
    static Deque<Integer> protectd = new ArrayDeque<>();
    static Deque<Integer> unprotected = new ArrayDeque<>();
   
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next());
        for (int i = 1;i<=N;i++) {
            int bank = Integer.parseInt(next());
            if (!guard[bank]) {
                guard[bank] = true; fst[i] = true;
                protectd.addLast(bank);
            }
        }
        if (protectd.size() == 1) {
            System.out.println(-1); return;
        }
        for (int j = 1;j<=N;j++) {
            if (!guard[j]) {unprotected.addLast(j);}
        }
        protectd.addLast(protectd.getFirst());
        protectd.removeFirst();
        for (int i = 1;i<=N;i++) {
            if (fst[i]) {
                System.out.print(protectd.getFirst() + " ");
                protectd.removeFirst();
            } else {
                System.out.print(unprotected.getFirst() + " ");
                unprotected.removeFirst();
            }
        }

    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
