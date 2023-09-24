import java.util.*;
import java.io.*;

public class SAC2022C4JP2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(next()), queries = Integer.parseInt(next());
        String plygns[] = new String[n]; 

        for (int i = 0;i<queries;i++) { 
            String[] query = br.readLine().trim().split(" "); 
            if (query[0].contains("get")) {
                if (plygns[Integer.parseInt(query[2])-1] != null && plygns[Integer.parseInt(query[2])-1].contains(query[1])) { System.out.println("1");} else {System.out.println("0"); }
            } else {
                plygns[Integer.parseInt(query[2])-1] = query[1];
            }
        }
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}