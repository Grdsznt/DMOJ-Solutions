// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.Collections;
// import java.util.PriorityQueue;
// import java.util.Queue;
// import java.util.StringTokenizer;
// import java.util.TreeSet;


// public class CCC2021S4 {
//     static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//     static StringTokenizer st;
//     static int N;
//     public static void main(String[] args) throws IOException {
//         N = Integer.parseInt(next()); int W = Integer.parseInt(next()), D = Integer.parseInt(next()); 
//         int perm[] = new int[N+1], idx[] = new int [N+1];
//         TreeSet<Pair<Integer, Integer>> st = new TreeSet<>((p1, p2) -> {
//             int compareFirst = p1.getFirst().compareTo(p2.getFirst());
//             if (compareFirst != 0) {
//                 return compareFirst;
//             }
//             return p1.getSecond().compareTo(p2.getSecond());
//         });
//         ArrayList<Integer>[] walk = new ArrayList[N+1];
            
//         for(int i = 1;i<=N;i++) {
//             walk[i] = new ArrayList<>();
//         }
//         for (int i = 0;i<W;i++) {
//             walk[Integer.parseInt(next())].add(Integer.parseInt(next()));
//         }
//         int[] dist = BFS(walk, N);
//         for (int i = 1;i<=N;i++) {
//             perm[i] = Integer.parseInt(next()); idx[perm[i]] = i-1; 
             
//         }
//         for (int i = 1;i<=N;i++) {
//             st.add(new Pair<>(idx[i] + dist[i], i));
//         }
        
//         for (int i = 0;i<D;i++) {
//             int x = Integer.parseInt(next()), y = Integer.parseInt(next());
//             int permx = perm[x], permy = perm[y];
//             st.remove(new Pair<>(idx[permx] + dist[permx], permx));
//             st.remove(new Pair<>(idx[permy] + dist[permy], permy));
//             int tmp;
//             tmp = idx[permy] ; idx[permy] = idx[permx]; idx[permx] = tmp;
//             tmp = perm[y]; perm[y] = perm[x]; perm[x] = perm[y];
//             st.add(new Pair<>(idx[permx] + dist[permx], permx)); 
//             st.add(new Pair<>(idx[permy] + dist[permy], permy));
//             System.out.println(st.first().first);
//         }
//     }

//     static class Pair<A, B> {
//         private final A first;
//         private final B second;
    
//         public Pair(A first, B second) {
//             this.first = first;
//             this.second = second;
//         }
    
//         public A getFirst() {
//             return first;
//         }
    
//         public B getSecond() {
//             return second;
//         }
//     }

//     static int[] BFS(ArrayList<Integer>[] adj, int source) {
//         Queue<Integer> queue = new PriorityQueue<>(); boolean visited[] = new boolean[N+1]; int dist[] = new int[N+1];
//         Arrays.fill(dist, 1000000000);
//         visited[source] = true; dist[source] = 0;
//         queue.add(source);
//         while (!queue.isEmpty()) {
//             int v = queue.remove();
            
//             for (int i: adj[v]) {

//                 if (!visited[i]) {
//                     visited[i] = true;
//                     dist[i] = dist[v] + 1;
//                     queue.add(i);
//                 }
//             }

//         }
//         return dist;
        
//     }

//     static String next () throws IOException {
//         while (st == null || ! st.hasMoreTokens())
//             st = new StringTokenizer(br.readLine().trim());
//         return st.nextToken();
//     }

// }

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class CCC2021S4 {
    static final int MM = 200006;
    static int N, W, D;
    static int[] s = new int[MM];
    static int[] idx = new int[MM];
    static int[] dis = new int[MM];
    static List<Integer>[] adj = new ArrayList[MM];
    static boolean[] vis = new boolean[MM];
    static TreeSet<Pair<Integer, Integer>> set = new TreeSet<>((p1, p2) -> {
        int compareFirst = p1.getFirst().compareTo(p2.getFirst());
        if (compareFirst != 0) {
            return compareFirst;
        }
        return p1.getSecond().compareTo(p2.getSecond());
    });

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        
        N = Integer.parseInt(next()); int W = Integer.parseInt(next()), D = Integer.parseInt(next()); 

        for (int i = 0; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 1; i <= W; i++) {
            int u = Integer.parseInt(next());
            int v = Integer.parseInt(next());
            adj[v].add(u);
        }

        bfs(N);

        for (int i = 1; i <= N; i++) {
            s[i] = Integer.parseInt(next());
            idx[s[i]] = i - 1;
        }

        for (int i = 1; i <= N; i++) {
            set.add(new Pair<>(idx[i] + dis[i], i));
        }

        for (int i = 1; i <= D; i++) {
            int x = Integer.parseInt(next());
            int y = Integer.parseInt(next());
            int sx = s[x];
            int sy = s[y];
            set.remove(new Pair<>(idx[sx] + dis[sx], sx));
            set.remove(new Pair<>(idx[sy] + dis[sy], sy));
            swap(idx, sx, sy);
            swap(s, x, y);
            set.add(new Pair<>(idx[sx] + dis[sx], sx));
            set.add(new Pair<>(idx[sy] + dis[sy], sy));
            System.out.println(set.first().getFirst());
        }
    }

    static void bfs(int st) {
        Arrays.fill(dis, 1000000000);
        Queue<Integer> q = new LinkedList<>();
        q.add(st);
        dis[st] = 0;
        vis[st] = true;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    q.add(v);
                    dis[v] = dis[u] + 1;
                    vis[v] = true;
                }
            }
        }
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static class Pair<A, B> {
        private final A first;
        private final B second;
    
        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
    
        public A getFirst() {
            return first;
        }
    
        public B getSecond() {
            return second;
        }
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

}
