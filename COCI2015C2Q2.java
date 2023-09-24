import java.util.*;
import java.io.*;

public class COCI2015C2Q2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), M = Integer.parseInt(next());
        int[][] cantBW = new int[M][2];
        HashSet<Integer> hashs = new HashSet<>();
        for (int i=0;i<M;i++) {
            int a = Integer.parseInt(next()), b = Integer.parseInt(next());
            cantBW[i][0] = a; cantBW[i][1] = b;
        }
        
        System.out.println(getComb(1, N, hashs, cantBW));


    }   

    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }

    // static int getComb(int i, int n, List<Integer> comb, int[][] arr, int count) {
        
    //     boolean include = true;
    //     for (int j = 0; j<arr.length; j++) {
    //         if (comb.contains(arr[j][0]) && comb.contains(arr[j][1])) {
    //             include = false;
    //         }
    //     }
	// 	if(i > n) {
    //         if (include == true) {
    //             return 1;
    //         } else {
    //             return 0;
    //         }
            
	// 	}
       
        
    //     count += getComb(i+1, n, comb, arr, count); //don't choose 
    //     comb.add(i);  
    
        
    //     count += getComb(i+1, n, comb, arr, count);
    //     comb.remove(comb.size() - 1);
        
    //    //choose 
        
    //     return count;
	// }
    static int getComb(int i, int n, HashSet<Integer> comb, int[][] arr) {
        if (i == n+1) {
            if (isValid(comb, arr)) {
                return 1;
            } else {
                return 0;
            }
        }
        
        int count = getComb(i+1, n, new HashSet<>(comb), arr); //don't choose 
        comb.add(i);  
        count += getComb(i+1, n, new HashSet<>(comb), arr); //choose 
        return count;
    }
    
    static boolean isValid(HashSet<Integer> comb, int[][] arr) {
        for (int j = 0; j < arr.length; j++) {
            if (comb.contains(arr[j][0]) && comb.contains(arr[j][1])) {
                return false;
            }
        }
        return true;
    }
}
