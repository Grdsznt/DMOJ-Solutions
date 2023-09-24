



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DMOPC2020C5P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        String s = next(), t = next(); boolean isEqual = false;
        int minLen = Math.min(s.length(), t.length());
        for (int i = 0;i<minLen;i++) {
            if (s.charAt(i) != t.charAt(i)) {
                System.out.println(s.length()+t.length()-2*(i)); return;
            } 
            if (i == minLen && (minLen == s.length() && minLen == t.charAt(i))) isEqual = true;
        }
        if (isEqual) {System.out.println(0);}
        else  System.out.println(Math.abs(s.length()-t.length()));

        
        
    }
 
    
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


