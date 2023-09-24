import java.util.*;
import java.io.*;

public class SAC2022C5P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int N = Integer.parseInt(next()); 
        String s = next();
        if (N % 2 == 0) {
            if(s.equals("left")) {
                System.out.println("right");
            } else {
                System.out.println("left");
            }
        } else {
            System.out.println(s);
        }
        
       
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}