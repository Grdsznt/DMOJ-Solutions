
import java.io.*;
import java.util.*;

public class DMOPC2020C1P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(next()), D = Integer.parseInt(next());
        ArrayList<Integer> a = new ArrayList<>(), b = new ArrayList<>();
        a.add(0); b.add(0);
        for (int i = 0;i<N;i++) {
            int k = Integer.parseInt(next());
            a.add(k); b.add(k);
        }
        for (int i = 1;i<=N;i++) {
            a.set(i, a.get(i-1) + a.get(i));
        }
        
        for (int i = 0;i<D;i++) {
            int n = Integer.parseInt(next());
            
            int sumr = (a.get(a.size()-1) - a.get(n)); int suml = (a.get(n));
            if (sumr > suml) {
                System.out.println(sumr);
                for (int j = a.size()-1;j>n;j--) {
                    a.remove(j);
                }
            } else {
                System.out.println(suml);
                for (int j = 1;j<=n;j++) {
                    a.remove(j);
                    
                }
                for (int j = n;j<=a.size()-1;j++) {
                    if (j == n) {
                        a.set(j, b.get(j+1));
                    } else {
                        a.set(j, a.get(j-1) + b.get(j+1));
                    }
                }
            }

        }
    
    }


    static String next () throws IOException { 
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}