import java.util.*;

import java.io.*;

public class AMathContestP2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int mod = 1000000007;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()); long sum = 0; 
        for (int i = 0;i<N;i++) {
            sum += Integer.parseInt(next()); sum = sum % mod;
        }
        System.out.println((sum * qpow(2, N-1, mod)) % mod);
        
    }
    
    // static int genCombs (int i, int n, List<Integer> comb, int sum){
    //     if (i > n) {
    //         for (int j:comb) {
    //             sum += j % mod ;
    //         }
    //         return sum;
    //     } 
    //     sum = genCombs(i+1, n, comb, sum);
    //     comb.add(a[i-1]); sum = genCombs(i+1, n, comb, sum); comb.remove(comb.size()-1);
    //     return sum;
    // }

    static long qpow(int base, int exp, int mod) {
        if(exp == 0) return 1;
    	long t = qpow(base, exp/2, mod);
    	t = t*t % mod;
    	if(exp % 2 == 0) return t;
    	return t*base % mod;
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }   
}


