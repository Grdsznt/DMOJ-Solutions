import java.util.*;
import java.io.*;

public class DMOPC2022C4P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException{
        int N = Integer.parseInt(next()), M = Integer.parseInt(next()), K = Integer.parseInt(next()), da[] = new int[N], ans = 0, left=0, right=0;
        
        
        for (int i = 0;i<N;i++) {da[i] = Integer.parseInt(next());}
        if (N == 1)  {
            if (K == 0) {
                System.out.println(Math.max(da[0] - 1, M - da[0])); return;
            }else { 
                if (da[0] - K < 1) {
                    ans = Math.max(da[0]-1, M-left-1);
                    
                }   
                else if(right + K > M) { 
                    if (left - K < 1 ) {
                        ans = Math.max(M-left-1, right-1);
                    } else {
                        System.out.println(Math.max(M-left-1, right-(left-K)-1));
                    }
                }
                else {
                    System.out.println(Math.max(M-(da[0]-K)-1, da[0]+K - 1)); return;
                }
            }
        }
        else {
            //get the max interval
            //get the max of moving the left K units left or the right K units right. Print
            for (int i = 0; i < N - 1; i++) {
                
                int dist = da[i+1] - da[i] - 1;
                if (dist > ans) {
                    ans = dist;
                    left = da[i]; right = da[i+1];
                }
                

                // int leftDist = da[i] - 1;
                // int rightDist = da[i + 1] - da[i] - 1;
                // int totalTime = leftDist + rightDist + 1;

                // if (leftDist <= K || rightDist <= K) {
                //     int newDist = Math.min(K, leftDist);
                //     int newTime = leftDist - newDist + rightDist + 1;

                //     if (i == 0) {
                //         ans = newTime;
                //     } else {
                //         ans = Math.max(ans, newTime);
                //     }    
                // } else {
                //     ans = Math.max(ans, totalTime);
                // }
            }
            if (left - K < 1) {
                if (right + K > M) {
                    ans = Math.max(right-1, M-left-1);
                } else {
                    ans = Math.max(right-1, (right+K)-left-1);
                }
            }
            else if(right + K > M) { 
                if (left - K < 1 ) {
                    ans = Math.max(M-left-1, right-1);
                } else {
                    ans = Math.max(M-left-1, right-(left-K)-1);
                }
            }
            else {ans = Math.max((right+K)-(left)-1, right-(left-K)-1);}

            System.out.println(ans);
        }
        // else {
        //     for (int i = 0;i<N-1;i++) {lst.add(new pair(da[i], da[i+1]));}
        // }
        // int ans = 0, md = 0, indx = 0;
        // for (int i = 0;i<lst.size();i++) {
        //    pair p = lst.get(i);
        //    int duration = p.s - p.f - 1;
        //    ans = Math.max(duration, ans);
        //     if (duration > md) {
        //         md = duration;
        //         indx = i;
        //     }
        // }
        // pair p = lst.get(indx);
        // if (p.s + K >= M) {
        //     if (!(p.f - K < 1)) {
        //         ans = Math.max(ans, p.s - (p.f - K)-1);
        //     } else {
        //         ans = Math.max(ans, p.s-2);
        //     }
        //     ans = Math.max(ans, M - p.f-1);
        // }
        // else ans = Math.max(ans,  p.s + K - p.f-1);

       
    }
    
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}