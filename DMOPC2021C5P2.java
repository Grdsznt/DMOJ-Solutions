



import java.util.*;
import java.io.*;

public class DMOPC2021C5P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        
        int N = Integer.parseInt(next());
        if (N == 1) {
            System.out.println("1"); return;
        } else if (N == 3) {
            System.out.println("1 3 2"); return;
        } else if (N == 4) {
            System.out.println("1 3 2 4"); return;
        } else if (N == 2) {
            System.out.println("-1"); return;
        } else if (N == 5) {
            System.out.println("4 5 1 2 3"); return;
        }
        System.out.print("4 5 ");
        for (int i = 1;i<=N;i++) {
            if (i == 4 || i == 5) continue;
            System.out.print(i != N ? i + " ": i);
            
        }
        System.out.print("\n");
        
    }

 
        
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    
}


