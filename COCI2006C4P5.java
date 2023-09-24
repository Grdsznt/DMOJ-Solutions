import java.util.*;
import java.io.*;

public class ICPCPACNW2016C {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {\
        node root = new node(1);
        int n = Integer.parseInt(next()), k = Integer.parseInt(next()), r = Integer.parseInt(next()), a[] = new int[n], ans = 0;
        for (int i = 0; i < k; i++) {
            a[Integer.parseInt(next())-1] = 1;
        }
        Arrays.sort(a); hi = a[a.length-1];

        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (check(mid)) {
                ans = mid;
                lo = mid+1;
            }else {
                hi = mid-1;
            }
        }
        
        System.out.println(ans);
        
        

    }

    

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }


}


class node {
    int number;
    node left;
    node right;

    node(int number) {
        this.number = number;
        this.right = null;
        this.left = null;
    }
}

