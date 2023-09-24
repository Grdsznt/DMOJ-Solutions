import java.util.*;
import java.io.*;

public class COCI07Q2 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int num = Integer.parseInt(next());
        List<Integer> list = new ArrayList<>();
        List<List<Integer>> list2 = new ArrayList<>();
        boolean[] used = new boolean[num];
        getPerm(num, used, list, list2);
    }

    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
    static List<List<Integer>> getPerm(int n, boolean used[], List<Integer> perm, List<List<Integer>> nd) {
    if (perm.size() == n) {
      nd.add(perm);
      return nd;
    }
    for (int i=1;i<=n;i++) {
      if (!used[i]) {
        used[i] = true; perm.add(i);
        getPerm(n, used, perm, nd);
        used[i] = false; perm.remove(perm.size()-1);
      }
    }
    return nd;
  }
  static List<List<Integer>> myPerm(int[] source, boolean used[], List<Integer> perm, List<List<Integer>> nd) {
    if (perm.size() == source.length) {
      nd.add(perm);
      return nd;
    }
    for (int i=1;i<=n;i++) {
      if (!used[i]) {
        used[i] = true; perm.add(source[i]);
        getPerm(source, used, perm, nd);
        used[i] = false; perm.remove(perm.size()-1);
      }
    }
  }
}