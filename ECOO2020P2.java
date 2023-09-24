

import java.util.*;
import java.io.*;

public class ECOO2020P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int T = Integer.parseInt(next());
        for (int i = 0;i<T;i++) {
            // col 0 = name, col 1 = price, col 2 = qty
            Map<String, List<pair>> table =  new HashMap<>();
            int N = Integer.parseInt(next()), ans = 0;
            
            for (int j = 0;j<N;j++) {
                int M = Integer.parseInt(next()); 
                for (int k = 0;k<M;k++) {
                    String s = next();
                    if (table.get(s) != null) {
                        table.get(s).add(new pair(Integer.parseInt(next()), Integer.parseInt(next())));
                    } else {
                        table.put(s, new ArrayList<pair>());
                        table.get(s).add(new pair(Integer.parseInt(next()), Integer.parseInt(next())));
                    }
                }
            }
            for (String s: table.keySet()) {
                List<pair> list = table.get(s);
                Collections.sort(list, (x, y) -> {
                    if (x.x != y.x) {
                        return Integer.compare(x.x, y.x);
                    } else {
                        return -Integer.compare(x.y, y.y);
                    }
                    } );
                
            }


            // sort first by price   
            int K = Integer.parseInt(next());
            for (int j = 0;j<K;j++) {
                String s = next(); int D = Integer.parseInt(next()), amt = 0;
                List<pair> list = table.get(s);
                for (pair p: list) {
                    ans += p.x * Math.min(D, p.y);
                    D -= Math.min(D, p.y);
                    // if (p.y - D < 0) {
                    //     if (amt+p.y < D) {
                    //         ans += p.x*p.y; p.y -= p.y; amt += p.y;
                    //     } else {
                    //         ans += p.y*D-amt; p.y -= (D-amt); 
                    //         break;
                    //     }
                    // } else {
                    //     ans += p.x*D; p.y -= D; amt += D;
                    //     break;
                    // }
                    
                    // add to amt until amt = D (the order has been fulfilled completely)
                    // subtract the amts added to amt for until it has been fulfilled using all of the pairs if necessary
                    // if (p.y <= 0) continue; // skip if item is sold out
                    // if (amt < D) {
                    //     if (amt + p.y <= D) {
                    //         ans += p.x * p.y;
                    //         amt += p.y;
                    //         p.y = 0;
                    //     } else {
                    //         ans += p.x * (D - amt);
                    //         p.y -= (D - amt);
                    //         amt = D;
                    //         break;
                    //     }
                    // } else {
                    //     break;
                    // }
                    
                    
                    
                }
                
                
            }
            System.out.println(ans);

        }
        
    }

    static class pair {
        int x;
        int y;
        pair(int x, int y) {
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


