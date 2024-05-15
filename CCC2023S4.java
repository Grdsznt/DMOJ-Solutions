import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class CCC2023S4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int N = Integer.parseInt(next()), M = Integer.parseInt(next());
        Map<Integer, ArrayList<triple>> graph = new HashMap<>();
        // add another list to keep track of edges for faster access

        for (int i = 0;i<M;i++) {
            int ui = Integer.parseInt(next());
            if (graph.get(ui) == null) {
                triple t = new triple(Integer.parseInt(next()), Integer.parseInt(next()), Integer.parseInt(next()));
                ArrayList<triple> list = new ArrayList<>(); list.add(t);
                graph.put(ui, list); 
                
            } else {
                ArrayList<triple> list = graph.get(ui);
                list.add(new triple(Integer.parseInt(next()), Integer.parseInt(next()), Integer.parseInt(next())));
            }
            
        }
        Collections.sort(graph.get(), (x, y) -> -Integer.compare(x[0], y[0]));

        djikstra(, graph);
    }

    static Map<Integer, Integer> djikstra (int start, Map<Integer, ArrayList<triple>> graph) {
        Map<Integer, Integer> distances = new HashMap<>();
        for (int node:graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);

        Set<Integer> queue = new HashSet<>(graph.keySet());

        while (!queue.isEmpty()) {
            int u = queue.iterator().next();
            int minValue = distances.get(u);
            for (int v: queue) {
                if (distances.get(v) < minValue) {
                    minValue = distances.get(v);
                    u = v;
                }
            }
            queue.remove(u);
            
            for (triple w:graph.get(u)) {
                if (distances.get(w.node) > distances.get(u) + w.weight) {
                    distances.put(w.node, distances.get(u) + w.weight);
                }
            }
        }

        return distances;
    }

    // prim with djikstra or sm
    static class triple {
        int node, length, weight;
        triple(int n, int l, int w) {
            this.node = n;
            this.weight = w; this.length = l;
        }
    } // calculate the sum of them and use minimum sum

    static String next() throws IOException{
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
