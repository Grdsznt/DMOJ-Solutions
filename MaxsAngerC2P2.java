



import java.util.*;
import java.io.*;

public class MaxsAngerC2P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        
        // int N = Integer.parseInt(next()) M = Integer.parseInt(next());
        System.out.println(get_hash("hello"));
        
        
    }

    static int get_hash(String s) {
        int hash = 0;
        for (int i = 0; i < s.length(); i++) {
            hash = hash * 13 + s.charAt(i) - 'a' + 1;
        }
        return hash;
    }

    static String getString(int hash) {
        String s = "";
        for (int i = 0;i<String.valueOf(hash).length();i++) {
            char a = 
            s = 
        }
    }
 
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


