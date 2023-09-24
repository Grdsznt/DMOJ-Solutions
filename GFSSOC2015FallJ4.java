import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GFSSOC2015FallJ4 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        
        String[] NQ = (br.readLine().trim()).split(" ");
        
        String[] Ratings = (br.readLine().trim()).split(" ");

        int[] psa = new int[Ratings.length];
        psa[0] = Integer.parseInt(Ratings[0]);
        for (int i = 0; i<Ratings.length-1; i++) {
            psa[i+1] = psa[i] + Integer.parseInt(Ratings[i+1]);
        }
        
        int[] output = new int[Integer.parseInt(NQ[1])];
        
        for (int i = 0; i<Integer.parseInt(NQ[1]); i++) {
            String[] s2 = (br.readLine().trim()).split(" ");
            int[] sToInt = new int[s2.length];
            for(int j = 0; j < s2.length; j++) {
                sToInt[j] = Integer.parseInt(s2[j]);
            }

            if (sToInt[0] == 1) {
                int LR = 0;
                int RR = psa[psa.length-1] - psa[sToInt[1]-1];
                output[i] = RR+LR;
            } else {
                int LR = psa[sToInt[0]-2];
                int RR = psa[psa.length-1] - psa[sToInt[1]-1];
                output[i] = RR+LR;
            }


        }

        for (int x = 0; x<output.length;x++) {
            System.out.println(output[x]);
        }

        
    
    }
}