import java.util.*;
import java.io.*;
public class J2easiestlol {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        String[] inputs = br.readLine().trim().split(" ");
        int[] inputs2 = new int[inputs.length];
        for (int j = 0;j<inputs.length;j++) {
            inputs2[j] = Integer.parseInt(inputs[j]);
        }
        //inputs[0] is nu\
        int Andrew = 0; int Tommy = 0; 
        for (int i = 0;i<inputs2[0];i++) {
            String[] input = br.readLine().trim().split(" ");
            if (inputs2[1] > Integer.parseInt(input[0])) {
                ++Andrew;
            } else {
                Andrew += 2;
            }
            if (inputs2[2] >= Integer.parseInt(input[1])) {
                ++Tommy;
            } else {
                Tommy += 2;
            }
        }
        if (Andrew > Tommy) {
            System.out.println("Tommy Wins!");
        } else if(Tommy > Andrew) {
            System.out.println("Andrew Wins!");
        } else {
            System.out.println("Tie!");
        }
        

    }
    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}
