import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BinaryIndexedTreeTest {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static long[] bit, bit2;
    public static void main(String[] args) throws IOException{
        int N = Integer.parseInt(next()), M = Integer.parseInt(next());
        bit = new long[N+1]; bit2 = new long[100001];
        int[] a = new int[N+1];
        for (int i = 1;i<=N;i++) {
            a[i] = Integer.parseInt(next());
            construct(i, a[i], bit); construct(a[i], 1, bit2);
        }

        
        for (int i = 0;i<M;i++) {
            String[] s = br.readLine().split(" ");
            
            switch (s[0]){
                case "C":
                    update(Integer.parseInt(s[1]), Integer.parseInt(s[2]), bit);
                    
                    update(a[Integer.parseInt(s[1])], -1, bit2); // got issues.
                    update(Integer.parseInt(s[2]), 1, bit2); a[Integer.parseInt(s[1])] = Integer.parseInt(s[2]);
                    break;
                case "S":
                    System.out.println(sumLR(Integer.parseInt(s[1]), Integer.parseInt(s[2])));
                    break;
                default:
                    System.out.println(sum(Integer.parseInt(s[1]), bit2));
                    break;

            }
        }
    }

    

    static void update(int indx, int val, long[] tree){ 

        long value = val-tree[indx]; 
        
        while (indx <= tree.length-1){
            tree[indx] += value;
            indx += indx & -indx;
        }

    }


    static void construct(int indx, int val, long[] tree) {
        while (indx <= bit.length-1){
            tree[indx] += val;
            indx += indx & -indx;
        }
    }

    


    
    
    static long sum(int indx, long[] tree) {
        long sum = 0; 
        while(indx > 0){
            sum += tree[indx];
            indx -= indx & -indx;
        }
        return sum;
    }

    static long sumLR(int l, int r) {
        return sum(r, bit) - sum(l-1, bit);
    }


    

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

}
