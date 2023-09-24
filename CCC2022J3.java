
import java.io.*;


public class CCC2022J3 {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException{

        StringBuffer str = new StringBuffer(br.readLine().trim());
        
        for (int i = 1; i<str.length(); i++) {
            if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z' && Character.isDigit(str.charAt(i-1))) {
                str.insert(i, "^");
            }
        }

        String s = str.toString();

        s = s.replace("-", " loosen ");
        s = s.replace("+", " tighten ");
        s = s.replace("^", "\n");

        System.out.println(s);
    }
}
