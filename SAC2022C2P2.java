import java.util.*;
import java.io.*;
public class SAC2022C2P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int K = Integer.parseInt(next());
        char[] teacher = br.readLine().toCharArray();
        
        for (char a = 'a' ;a<='z';a++) {
            for (char b = 'a';b<='z';b++) {
                for (char c = 'a';c<='z';c++) {
                    for (char d = 'a';d<='z';d++) {
                        int sum = dist(a, teacher[0]) + dist(b, teacher[1]) + dist(c, teacher[2]) + dist(d, teacher[3]);
                        if (sum<=K) {System.out.println("" + a + b + c + d);}
                        
                    }
                }
               
            }
        } 


    }

    
    static int dist(char x, char y) {
        int dist = Math.abs(x-y); 
        return  Math.min(dist, 26-dist);

    }
    
    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}
