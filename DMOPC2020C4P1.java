import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class DMOPC2020C4P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    // public static void main(String[] args) throws NumberFormatException, IOException{
    //     List<Integer> lst = new ArrayList<>();
    //     // generate combinations
    //     int T = Integer.parseInt(next());
    //     for (int i = 0;i<T;i++) {
    //         int N = Integer.parseInt(next()), S = Integer.parseInt(next());
    //         System.out.println(getComb(1, N, S, lst));
    //     }    
    // }

    // static int getComb (int st, int end, int target, List<Integer> combs) {
    //     int sol = 0, sum = 0;
    //     if (st > end) {
    //         for (int i:combs) sum += i;
    //         if (sum == target && combs.size() == end-2) {
    //             ++sol;
    //         }
    //         return sol;
    //     } 
    //     sol += getComb(st+1, end, target, combs);
    //     combs.add(st); sol += getComb(st+1, end, target, combs); combs.remove(combs.size()-1);
    //     return sol;
    // }
    public static void main(String[] args) throws NumberFormatException, IOException{
        
        int T = Integer.parseInt(next());
        for (int i = 0;i<T;i++) {
            long N = Integer.parseInt(next()), sol = 0, S = Long.parseLong(next());
            long sum = (N*(N+1)/2) - S;
            for (long j = 1;j<=(N+1);j++) {
                long k = sum-j;
                if (k <= N && j < k) ++sol;
            }
            System.out.println(sol);
        }    
    }
    

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
