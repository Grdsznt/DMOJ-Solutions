import java.util.*;
import java.io.*;
public class CCC2005S1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    

    public static void main(String[] args) throws IOException {
        
        Map<Character, Integer> map = new HashMap<>();
        map.put('A', 2); 
        map.put('B', 2);
        map.put('C', 2);
        map.put('D', 3);
        map.put('E', 3);
        map.put('F', 3);
        map.put('G', 4);
        map.put('H', 4);
        map.put('I', 4);
        map.put('J', 5);
        map.put('K', 5);
        map.put('L', 5);
        map.put('M', 6);
        map.put('N', 6);
        map.put('O', 6);
        map.put('P', 7);
        map.put('Q', 7);
        map.put('R', 7);
        map.put('S', 7);
        map.put('T', 8);
        map.put('U',8);
        map.put('V', 8);
        map.put('W', 9);
        map.put('X',9);
        map.put('Y', 9);
        map.put('Z', 9);
        int t = Integer.parseInt(next());
        String[] output = new String[t];
        for (int i = 0;i<t;i++) {
            String s = next(), u = ""; s = s.replace("-", ""); 
            s = s.substring(0, 10);
            for (int j = 0;j<10;j++) {
                if (!Character.isDigit(s.charAt(j))) {
                    if (j == 3 || j == 6) {
                        u = u + "-" + Integer.toString(map.get(s.charAt(j)));
                    } else {
                        u = u + Integer.toString(map.get(s.charAt(j)));
                    }
                    
                } else {
                    if (j == 3 || j == 6) {
                        u = u + "-" + s.charAt(j);
                    } else {
                        u = u + s.charAt(j);
                    }
                }
            }
            output[i] = u;
        }
        for (String k:output) {
            System.out.println(k);
        }
    }

    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}