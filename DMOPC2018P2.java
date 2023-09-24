import java.io.*;
import java.util.*;
public class DMOPC2018P2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), K = Integer.parseInt(next()), a[] = new int[N];
        for (int i = 0;i<N;i++) { a[i] = Integer.parseInt(next()); } 
        if (K == 1) {
            System.out.println("YES");
        } else {
            System.out.println(sort(a, K, 0) ? "YES" : "NO");
        }
        
    }

    // static boolean sort(int[] a, int K) {
    //     int temp = 0;
    //     for (int i = 0;i<a.length;i++) {
    //         if (a[i] != i + 1 && i+K < a.length) {
    //             temp = a[i];
    //             a[i] = a[i+K];
    //             a[i+K] = temp;
                
    //         } else {
                
    //         }
    //     }

    // }

    // static boolean sort(int[] a, int K, int indx) {
    //     if (indx == a.length - 1) {
    //         return check(a);

    //     } else {
    //         //recurse through every possiblity given this node
    //         for (int i = indx;i<a.length;i++) {
    //             if (i+K<a.length) {
    //                 if (K == Math.abs(i-indx)) {
    //                     if (a[indx] == indx+1) {
    //                         continue;
    //                     }
    //                     int temp = a[i];
    //                     a[i] = a[i+K];
    //                     a[i+K] = temp;
    //                     if (sort(a, K, indx+1)) {
    //                         return true;
    //                     }
    //                     temp = a[i];
    //                     a[i] = a[i+K];
    //                     a[i+K] = temp;
    //                 }
                    
    //             }
                
    //         }
    //         //return false if no path is found
    //         return false;
    //     }
        

    // }

    

    static boolean sort(int[] a, int K, int indx) {
        List<List<Integer>> lst = new ArrayList<>();

        for (int i = 0;i<K;i++) {
            
            lst.add(new ArrayList<>()); 
            
        }

        for (int i = 0;i<a.length;i++) {
            lst.get(i % K).add(a[i]);
        }

        for (int l = 0;l<K;l++) {
            Collections.sort(lst.get(l));
            int num = l + 1;
            
            for (int m: lst.get(l)) {
                if (num != m) {
                    return false;
                }
                num += K;
            }

            
        }
        return true;
    }


    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}


