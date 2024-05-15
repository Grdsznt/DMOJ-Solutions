import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class CCC2022S4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int X = Integer.parseInt(next()), violations = 0; String[] yes = new String[X];
        HashMap<String, Integer> d = new HashMap<>();
        for (int i = 0;i<X;i++) {
            yes[i] = br.readLine();
             
        }   
        int Y = Integer.parseInt(next()); String[] no = new String[Y];
        for (int i = 0;i<Y;i++) {
            no[i] = br.readLine();
        } 
        int G = Integer.parseInt(next()); 
        for (int i = 0;i<G;i++) {
            String[] s  = br.readLine().split(" ");
            d.put(s[0], i); d.put(s[1], i); d.put(s[2], i);
        }
        
        for (int i = 0;i<X;i++) {
            String [] y = yes[i].split(" ");
            if ((d.get(y[0])) != d.get(y[1])) violations++;
        }
        for (int i = 0;i<Y;i++) {
            String[] n = no[i].split(" ");
            if ((d.get(n[0]) == d.get(n[1]))) violations++;
        }
        System.out.println(violations);
    }

    static String next() throws IOException{
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
