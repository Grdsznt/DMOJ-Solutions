
import java.util.*;
import java.io.*;

public class BobandBusstops {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), Q = Integer.parseInt(next()), a[] = new int[N];
        for(int i = 0;i<N;i++) {
            a[i] = Integer.parseInt(next());
        }
        Arrays.sort(a);
        for (int i = 0;i<Q;i++) {
            int l = Integer.parseInt(next()), r = Integer.parseInt(next());
            System.out.println(upperbnd(a, r) - lowerbnd(a, l));
        }
    }
    
    static int upperbnd(int[] a, int key) {
        int l = 0, h = a.length-1, ans = a.length;
        while (l <= h) {
            int middle = (l+h)/2;
            if (a[middle] > key) {
                ans = middle; h = middle-1;
            } else {
                l = middle - 1;
            }
        }
        return ans;
    }
    static int lowerbnd(int[] a, int key) {
        int l = 0, h = a.length-1, ans = a.length;
        while (l <= h) {
            int middle = (l+h)/2;
            if (a[middle] <= key) {
                l = middle + 1;
                ans = middle;
            } else {
                h = middle-1;
            }
        }
        return ans;
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}


