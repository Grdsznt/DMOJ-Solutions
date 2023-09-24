
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.StringTokenizer;

public class AnAnimalC5P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int evens = 0, odds = 0;
        for(int i = Integer.parseInt(next());i > 0;i--) {
            if (Integer.parseInt(next()) % 2 == 0) evens++;
            else odds++;
        }
        System.out.println(odds/2 + evens/2);
        
        
    }
    
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}


