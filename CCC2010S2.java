



import java.util.*;
import java.io.*;

public class CCC2010S2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        Map<String, String> code = new HashMap<>();
        int n = Integer.parseInt(next());
        
        for (int i = 0;i<n;i++) {
            String s = next(), m = next(); 
            code.put(m, s);
        }
           
        String s = next(), ans = ""; int indx = 0, i = 0;
        while (i < s.length()) {
            String t = s.substring(i, i+indx);
            if (code.get(t) != null) {
                ans = ans + code.get(t); i+= indx;
                indx = 0;
            
            }
            indx++;
        }
        
        System.out.println(ans);
        
        
    }
 
    
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


