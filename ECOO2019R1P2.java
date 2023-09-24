import java.util.*;
import java.io.*;

public class ECOO2019R1P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        for (int i = 0;i<10;i++) {
            Map<String, String> m = new HashMap<>();
            int R = Integer.parseInt(next()), T = Integer.parseInt(next());
            String A = next();
            for (int j = 0;j<R;j++) {
                m.put(next(), next());    
            }
           
            for (int j = 0;j<T;j++) {
                int k = 0;
                while (k<A.length()) {
                    String s = Character.toString(A.charAt(k));
                    A = A.substring(0, k) + m.get(s) + A.substring(k+1, A.length()); 
                    k += (m.get(s).length());
                    
                }
                
            }
            System.out.println(A.charAt(0) + "" + A.charAt(A.length()-1) + " " + A.length());
        }
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
