



import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CCC2001J2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int x = Integer.parseInt(next()), m = Integer.parseInt(next());
        for (int i = 1;i<m;i++) {
            if ((x%m)*(i%m) % m == 1) {
                System.out.println(i); return;
            }
        }
        System.out.println("No such integer exists.");
       
        
    }
 
    
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


