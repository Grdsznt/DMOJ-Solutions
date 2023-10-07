    import java.util.*;
import java.io.*;

public class ShopandShip {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    // actually a pair but i call it tuple
    static class tuple {
        int city;
        int weight;
        tuple(int c , int w) {city = c;weight = w;}
    }
    // I store the graph in a map
    static Map<Integer, ArrayList<tuple>> journey = new HashMap<>();

    public static void main(String[] args) throws IOException, NumberFormatException {
        int n = Integer.parseInt(next()), t = Integer.parseInt(next());
        for (int i = 0;i<t;i++) {
            //ship from x to y takes cost
            String[] xyCost = br.readLine().trim().split(" ");
            addEdge(Integer.parseInt(xyCost[0]), Integer.parseInt(xyCost[1]), Integer.parseInt(xyCost[2]));
            //bidirectional
        }
        int k = Integer.parseInt(next());
        //2d array for storing
        int cities[][] = new int[k][2];
        for (int j = 0;j<k;j++) {
            // z is the country
            String[] ZP = br.readLine().trim().split(" ");
            for (int p = 0;p<2;p++) {
                cities[j][p] = Integer.parseInt(ZP[p]);
            }
        }
        int min = Integer.MAX_VALUE;
        int d = Integer.parseInt(next());
        for (int[] l:cities) {
            // get djikstra's from every country
            Map<Integer, Integer> map = new HashMap<>(djikstra(journey, l[0]));
            int cost = 0;
            for (int key: map.keySet()) {
                if (key == d) {
                    cost += map.get(key);
                    cost += cities[l[0]-1][1];
                    //get minimum
                    min = Math.min(cost, min);
                }
            }
        }
        System.out.println(min);
        //total cost min is calculated by buying the pen in every country (loop thru list), then starting djikstra from that list start)) and adding them all up
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    
    public static void addEdge(int x, int y, int weight) {
        if (!journey.containsKey(x)) {
            journey.put(x, new ArrayList<>());
        }
        journey.get(x).add(new tuple(y, weight));

        if (!journey.containsKey(y)) {
            journey.put(y, new ArrayList<>());
        }
        journey.get(y).add(new tuple(x, weight));
    }
    
    //standard djikstra algorithm from last homework but i converted to java and to work with my class
    public static Map<Integer, Integer> djikstra(Map<Integer, ArrayList<tuple>> graph, int source) {
        Map<Integer, Integer> dists = new HashMap<>();
        for (int key: journey.keySet()) {
            dists.put(key, Integer.MAX_VALUE);
        }
        dists.put(source, 0);

        Set<Integer> queue = new HashSet<>(journey.keySet());

        while (!queue.isEmpty()) {
            int u = queue.iterator().next();
            int minValue = dists.get(u);
            for (int a: queue) {
                if (dists.get(a) < minValue) {
                    minValue = dists.get(a);
                    u = a;
                }
            }
            queue.remove(u);

            for (ShopandShip.tuple s : journey.get(u)) {
                Integer old = dists.get(s.city);
                if (old == null) {
                    continue;
                }
                int notold = dists.get(u) + s.weight;
                if (old > notold) {
                    dists.put(s.city, notold);
                }
            }
        }
        return dists;

    }
}
