import java.util.*;
import java.io.*;

public class UCCCodingCompetition2021P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        String s = next(); int ans = 0;
        for (int i = 0;i<s.length();i++) {
            if (Character.getNumericValue(s.charAt(i)) == 2) {
                if (i != s.length()-1) {
                    if (Character.getNumericValue(s.charAt(i+1)) != 5) ans++;
                } else {
                    ans++;
                }
            }
        }       
        System.out.println(ans);
          
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }   
}


