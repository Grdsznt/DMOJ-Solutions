import java.util.*;
import java.io.*;
public class Stackblocks {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int height[], target, ans = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
		int n = Integer.parseInt(next()), target = Integer.parseInt(next());
        height = new int[n+1];  
		List<Integer> comb = new ArrayList<>();
		getComb(1, n, comb);
        System.out.println(ans);
	}
	static void getComb(int i, int n, List<Integer> comb) {
		if(i > n) {
			int sum = 0;
            for (int indx: comb) sum+=height[indx];
            if (sum >= target) ans = Math.min(ans, sum-target);
			return;
		}
		getComb(i+1, n, comb); //don't choose 
		comb.add(i);  getComb(i+1, n, comb);  comb.remove(comb.size() - 1); //choose 
	}
    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }

}
