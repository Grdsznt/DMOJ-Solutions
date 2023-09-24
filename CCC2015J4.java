import java.io.*;
import java.util.*;

public class CCC2015J4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
        int M = Integer.parseInt(next());
        
        int[] friendNum = new int[6];
        boolean[] sent = new boolean[6], recieved = new boolean[6];
        boolean hasWaited = false;
        int waitindx = 0;

        for (int i = 0;i<M;i++) {
            if (hasWaited == false) {
                waitindx = 0;
            }
            hasWaited = false;
            
            String[] texts = br.readLine().trim().split(" ");

            if (texts[0].equalsIgnoreCase("S")) {
                sent[Integer.parseInt(texts[1])] = true;
                recieved[Integer.parseInt(texts[1])] = false;
            } else if (texts[0].equalsIgnoreCase("W")) {
                for (int j = 0;j<friendNum.length;j++) {
                    if (friendNum[j] != 0 && sent[j] == false && recieved[j] == true) {
                        friendNum[j] += Integer.parseInt(texts[1]);
                        hasWaited = true;
                        waitindx = 1;
                    }
                }
            } else {
                recieved[Integer.parseInt(texts[1])] = true;
                sent[Integer.parseInt(texts[1])] = false;
            }
            //the problem is with the wait, after the wait we don't add until the next next action...
            // it only gets boosted at the first time
            for (int k = 0; k<friendNum.length;k++) {
                if (hasWaited == false) {
                    if (friendNum[k] != 0 && waitindx == 0 && recieved[k] == true) {
                        friendNum[k]++;
                    } else if(recieved[k] == true && friendNum[k] == 0) {
                        friendNum[k] = 1;
                    } 
                    
                } else {
                    break;
                }
                
            }
            

        }
        for (int m = 0;m<6;m++) {
            if (recieved[m] == true && sent[m] == false) {
                friendNum[m] = -1;
            }
        } 
        for (int l = 0;l<friendNum.length;l++) {
            if (friendNum[l] != 0) {
                System.out.println((l) + " " + (friendNum[l]));
            }
        }
        
    }

    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}