import java.io.*;
import java.util.*;

public class CCC2004S2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int n = Integer.parseInt(next()), k = Integer.parseInt(next()), ranks[] = new int[n+1], ties = 1;

        List<pair> lst = new ArrayList<>();

        for (int i = 1;i<=n;i++) {

            pair p = new pair(i, 0); lst.add(p);

        }
        for (int i = 0;i<k;i++) {

            for(int j = 0;j<n;j++) lst.get(j).y += Integer.parseInt(next());

            Collections.sort(lst, (x, y) -> {
                    if (x.y != y.y)  {
                        return -Integer.compare(x.y, y.y);
                    }else {
                        return Integer.compare(x.x, y.x);
                    }});

            for (int l = 1; l < n; l++) {
                pair p = lst.get(l);
                if (p.y == lst.get(l-1).y) {
                    ranks[lst.get(l-1).x] = Math.max(ranks[lst.get(l-1).x], l);
                    ranks[p.x] = Math.max(ranks[p.x], l);
                } else {
                    ranks[p.x] = Math.max(ranks[p.x], l);
                }
                
            }
        }
        for (int l = 0; l < n; l++) { 
                
                pair p = lst.get(l);

                if (l > 0 && p.y == lst.get(l-1).y) ties++; 
                
            }
        for (int i = 0;i<ties;i++) System.out.println("Yodeller " + lst.get(i).x + " is the TopYodeller: score " + lst.get(i).y + ", worst rank " + (ranks[lst.get(i).x]+1));
        
    }
    static class pair {
        int x;
        int y;
        
        pair (int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

}