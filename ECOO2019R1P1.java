import java.util.*;
import java.io.*;

public class ECOO2019R1P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        for (int i = 0;i<10;i++) {
            int N = Integer.parseInt(next()), M = Integer.parseInt(next()), D = Integer.parseInt(next()), a[] = new int[D], laundry = 0, totalShirts = N;
            for (int j = 0;j<M;j++) {
                a[Integer.parseInt(next())-1]++;
            }
            for (int j = 0;j<D;j++) {
                //at the end of the day it gets dirty
                if (N > 0) {N--;} 
                else {++laundry; N += totalShirts; N--;}
                if (a[j] != 0) {N += a[j]; totalShirts += a[j];}
                
            }
            System.out.println(laundry);
        }
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
