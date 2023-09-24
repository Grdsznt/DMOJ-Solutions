import java.io.*;
import java.util.*;
public class DMOPC2017P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static Map<Integer, String> dict = new HashMap<>();
   
    public static void main(String[] args) throws IOException {
        dict.put(0, "O");
        dict.put(1, "l");
        dict.put(3, "E");
        dict.put(4, "A");
        dict.put(5, "S");
        dict.put(6, "G");
        dict.put(8, "B");
        dict.put(9, "g");
       
        String s = br.readLine(), q = "";

        for (int i = 0;i<s.length();i++) { 
            if (dict.get(Character.getNumericValue(s.charAt(i))) != null) {
                q = q + dict.get(Character.getNumericValue(s.charAt(i)));
            } else {
                q = q + s.charAt(i);
            }
        }

        System.out.println(q);


    }

    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}
