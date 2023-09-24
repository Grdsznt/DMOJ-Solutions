import java.util.*;
import java.io.*;

public class CCC2015J4NMS {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int M = Integer.parseInt(next());
        int[] fren = new int[101], sent = new int[101];
        boolean[] rec = new boolean[101];
        int time = 0;

        for (int i = 0;i<M;i++) {

            String[] mssg = br.readLine().trim().split(" ");
            if (mssg[0].contains("S")) {
                fren[Integer.parseInt(mssg[1])] += time - sent[Integer.parseInt(mssg[1])];
                rec[Integer.parseInt(mssg[1])] = false;
            } else if (mssg[0].contains("R")) {
                rec[Integer.parseInt(mssg[1])] = true;
                sent[Integer.parseInt(mssg[1])] = time;
            } else {
                time += Integer.parseInt(mssg[1])-2;
            }
            time += 1;

        }
        for (int j = 0;j<fren.length;j++) {
            if (fren[j] != 0) {
                if (rec[j] == false) {
                    System.out.println(j+" " + fren[j]);
                } else {
                    System.out.println(j+" -1");
                }
            }   
        }


    }
    static String next() throws IOException{
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        } return st.nextToken();
    }
}

// M = int(input())
// f = [0]*101
// r = [0]*101
// s = [0]*101
// time = 0
// for i in range(M):
//     ss = input().split()
//     cmd = ss[0]
//     n = int(ss[1])
//     if cmd == 'S':
//         f[n] += time - s[n]
//         r[n] = 1
//     elif cmd == "R":
//         r[n] = -1
//         s[n] = time
//     else:
//         time += n-2
//     time += 1
// for j in range(101):
//     if r[j] != 0:
//         if r[j] > 0:
//             print(j, f[j])
//         else:
//             print(j, r[j])
