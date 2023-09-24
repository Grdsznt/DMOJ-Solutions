import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;
public class AvacadoTrees {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int N = Integer.parseInt(next()), Q = Integer.parseInt(next()), H = Integer.parseInt(next()), avocados[] = new int[N+1];
        pair[] trees = new pair[N]; 
        
        for(int i = 0;i<N;i++) {
            if (trees[i] == null) trees[i] = new pair(0, 0);
            trees[i].first = Integer.parseInt(next()); trees[i].second = Integer.parseInt(next()); 
        } // first is the height, second is the amount of avocados
        for (int j = 1;j<=N;j++) {
            if (trees[j-1].first <= H) avocados[j] = avocados[j-1] + trees[j-1].second;
            else avocados[j] = avocados[j-1];
        }
        
        int sol = 0;
        for (int i = 0;i<Q;i++) {
            int l = Integer.parseInt(next()), r = Integer.parseInt(next());
            int sum = avocados[r] - avocados[l-1];
            sol = Math.max(sol, sum);
            
        }
        
        System.out.println(sol);
    }

//     public static void main(String[] args) throws NumberFormatException, IOException {
//     int N = Integer.parseInt(next()), Q = Integer.parseInt(next()), H = Integer.parseInt(next());
//     pair[] trees = new pair[N];
//     for(int i = 0;i<N;i++) {
//         trees[i] = new pair(Integer.parseInt(next()), Integer.parseInt(next())); 
//     }
//     // Arrays.sort(trees); // sort trees by height
    
//     int[] prefixSum = new int[N+1];
//     for(int i = 0;i<N;i++) {
//         if (trees[i].first <= H) {
//             prefixSum[i+1] = prefixSum[i] + trees[i].second;
//         } else {
//             prefixSum[i+1] = prefixSum[i];
//         }
//     }
    
//     int max = 0;
//     for (int j = 0;j<Q;j++) {
//         int left = Integer.parseInt(next()) - 1, right = Integer.parseInt(next()) - 1;
//         int sol = prefixSum[right+1] - prefixSum[left];
//         max = Math.max(max, sol);
//     }
    
//     System.out.println(max);
// }

    static class pair {
        int first; int second;
        pair(int fs, int sd) {
            first = fs; second = sd;
        }
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
