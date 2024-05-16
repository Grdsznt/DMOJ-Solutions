import java.util.*;
import java.io.*;


public class CCO2010P3 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static HashMap<Integer, Integer> rnk = new HashMap<>(); static HashMap<Integer, Integer> rnk2 = new HashMap<>();
    static TreeSet<Integer> s = new TreeSet<>();
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next());
        for (int i = 0;i<N;i++) {
            String n = next();
            if (n.equals("N")) {
                int x = Integer.parseInt(next()), r = Integer.parseInt(next());
                rnk.put(x, r); rnk2.put(r, x); s.add(r);
            } else if (n.equals("Q")) {
                System.out.println(rnk2.get(s.toArray()[s.size()-Integer.parseInt(next())]));
            } else {
                int x = Integer.parseInt(next()), r = Integer.parseInt(next());
                int score = rnk.get(x);
                s.remove(score); 
                s.add(r);
                rnk.put(x, r);
                rnk2.put(r, x);
            }
        }
    }

    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }


}
