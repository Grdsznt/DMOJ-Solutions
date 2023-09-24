import java.util.*;
import java.io.*;

public class CCC2006S1 {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        String mother = next(), father = next();
        int X = readInt();

        // int[][] letterfreqM = new int[10][10];
        // int[][] letterfreqF = new int[10][10];
        
        for (int i = 0;i<X;i++) {
            String baby = next();
            boolean babyOrNOT = true;
            for (int j = 0; j<5;j++) {
                babyOrNOT = true;
                if (baby.charAt(j) == 'a') {
                    if (!mother.contains("a") || !father.contains("a")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'A') {
                    if (!mother.contains("A") && !father.contains("A")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'b') {
                    if (!mother.contains("b") || !father.contains("b")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'B') {
                    if (!mother.contains("B") && !father.contains("B")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'c') {
                    if (!mother.contains("c") || !father.contains("c")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'C') {
                    if (!mother.contains("C") && !father.contains("C")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'd') {
                    if (!mother.contains("d") || !father.contains("d")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'D') {
                    if (!mother.contains("D") && !father.contains("D")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'e') {
                    if (!mother.contains("e") || !father.contains("e")) {
                        babyOrNOT = false;
                        break;
                    }
                } else if (baby.charAt(j) == 'E') {
                    if (!mother.contains("E") && !father.contains("E")) {
                        babyOrNOT = false;
                        break;
                    }
                }

            }

            if (babyOrNOT == true) {
                System.out.println("Possible baby.");  
            } else {
                System.out.println("Not their baby!");
            }
            
        }
            
            
    }


    

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }  
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}



// for (int i = 1; i<10; i++) {
        //     for (int j = 0; j<10; j++) {
        //         letterfreqM[j][i] = letterfreqM[j][i-1];
        //     }
        //     if (Character.isUpperCase(mother.charAt(i)) == false) {
        //         letterfreqM[mother.charAt(i) - 'a'][i]++;
        //     } else {
        //         letterfreqM[mother.charAt(i)- 'A' + 5][i]++;
        //     }
            
        // }
        // for (int i = 1; i<10; i++) {
        //     for (int j = 0; j<10; j++) {
        //         letterfreqF[j][i] = letterfreqF[j][i-1];
        //     }
        //     if (Character.isUpperCase(father.charAt(i)) == false) {
        //         letterfreqF[father.charAt(i) - 'a'][i]++;
        //     } else {
        //         letterfreqF[father.charAt(i)- 'A' + 5][i]++;
        //     }
            
        // }