
import java.io.*;


public class CCC2020J4 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {

        String T = br.readLine().trim();
        char[] S = br.readLine().toCharArray();
        char[] temps = new char[S.length];
        String[] cyclicShifts = new String[S.length];
        boolean printed = false;

        for (int j = 0; j<S.length; j++) {
            for (int i = 0; i<S.length-1; i++) {
                
                temps[i] = S[i+1];
    
            }
            temps[temps.length-1] = S[0];
            cyclicShifts[j] = String.valueOf(temps);
            for (int k = 0; k<S.length;k++) {
                S[k] = temps[k];
            }
            
        }
        for (int k = 0; k<S.length;k++) {
            if (T.contains(cyclicShifts[k])) {
                System.out.println("yes");
                printed = true;
                break;
            } 
        }
        if (printed == false) {
            System.out.println("no");
        }

    }
}