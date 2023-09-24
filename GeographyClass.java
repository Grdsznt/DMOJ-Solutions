import java.util.*;
import java.io.*;

public class GeographyClass {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), a[] = new int[N], element; Set<Integer> set = new HashSet<>();
        
        for (int i = 0;i<N;i++) {
            a[i] = Integer.parseInt(next());
        }

        for (int i = 0;i<N;i++) {
            long sum = 0;
            element = a[i];
            if (element % Math.sqrt(element) == 0) {
                sum += element;
            }
            for (int j = 1;j < Math.sqrt(element);j++) {

                if (element % j == 0) {
                    sum += Math.pow(j, 2) + Math.pow(element/j, 2);
                }
            }
            System.out.println(sum);
            
            
        }
        

        

    }

    // static boolean isPrime(int n) {
    //     for (int i = 2;i*i<=n;i++) {
            
    //     }
    // }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }


}

