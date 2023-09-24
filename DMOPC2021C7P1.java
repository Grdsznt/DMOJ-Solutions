import java.io.BufferedReader;
import java.io.InputStreamReader;
// import java.util.HashSet;
// import java.util.Set;
import java.util.StringTokenizer;
import java.io.IOException;
public class DMOPC2021C7P1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N, M;
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        N = Integer.parseInt(next()); M = Integer.parseInt(next()); int a[][] = new int[N][M];
        // Set<Integer>[] rowSets = new Set[N];
        // Set<Integer>[] colSets = new Set[M];
        // for (int i = 0; i < N;i++) rowSets[i] = new HashSet<>();
        // for (int j = 0; j < M;j++) colSets[j] = new HashSet<>();
        
        for (int i = 0;i<N;i++) {
            for (int j = 0;j<M;j++) {
                a[i][j] = Integer.parseInt(next());
                // if (x != 0) {
                //     rowSets[i].add(x);
                //     colSets[j].add(x);
                // }
            }
        }

        for (int i = 0;i<N;i++) {
            for (int j = 0;j<M;j++) {
                if (a[i][j] == 0) {
                    if (i == 0 && j == 0) {
                        a[i][j] = 1;
                    } else if (i == 0) {
                        a[i][j] = a[i][j-1] + 1; 
                    } else if (j == 0) {
                        a[i][j] = a[i-1][j] + 1;
                    } else {
                        a[i][j] = Math.max(a[i][j-1], a[i-1][j]) + 1;
                    }
                    
                } else {
                    if (i > 0 && a[i][j] <= a[i-1][j]) {
                        System.out.println(-1);
                        return;
                    } else if (j > 0 && a[i][j] <= a[i][j-1]) {
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }

        for (int i = 0;i<N;i++) {
            for (int j = 0;j<M;j++) {
                System.out.print(a[i][j] + (j == M-1? "\n" : " "));
            }
        }
        // if (!solve(a, 0, 0)) {
        //     System.out.println(-1);
        // }
        
    }

    // static Boolean solve(int[][] a, int r, int c, Set<Integer>[] rowSets, Set<Integer>[] colSets) {
    //     if (c == M) {
    //         r++; c = 0;
    //         if (r == N) {
    //             for (int i = 0;i<N;i++) {
    //                 for (int j = 0;j<M;j++) {
    //                     System.out.print(a[i][j] + " ");
    //                 }
    //                 System.out.print("\n");
    //             }
    //             return true;
    //         }
    //     }
        

    //     if (a[r][c] != 0) {
    //         return solve(a, r, c+1, rowSets, colSets);
    //     }
        
    //     for (int i = 1;i<=100000000;i++) {
    //         if (!rowSets[r].contains(i) && !colSets[c].contains(i) ) {
    //             if(c == M) {
    //                 if (r == 0) {
    //                     if ((a[r][c-1] < i) && (a[r+1][c] > i || a[r+1][c] == 0)) {
    //                         a[r][c] = i;
    //                         rowSets[r].add(i);
    //                         colSets[c].add(i);
    //                         if (solve(a, r, c+1, rowSets, colSets)) {
    //                             return true;
    //                         }
    //                         a[r][c] = 0;
    //                         rowSets[r].remove(i);
    //                         colSets[c].remove(i);
    //                     }
    //                 } else if(r == N) {
    //                     if ((a[r][c-1] < i) && (a[r-1][c] < i)) {
    //                         a[r][c] = i;
    //                         rowSets[r].add(i);
    //                         colSets[c].add(i);
    //                         if (solve(a, r, c+1, rowSets, colSets)) {
    //                             return true;
    //                         }
    //                         a[r][c] = 0;
    //                         rowSets[r].remove(i);
    //                         colSets[c].remove(i);
    //                     }
    //                 }
                    
    //             } else if (c == 0) {
    //                 if (r == 0) {
    //                     if ((a[r][c+1] > i || a[r][c+1] == 0) && (a[r+1][c] > i || a[r+1][c] == 0)) {
    //                         a[r][c] = i;
    //                         rowSets[r].add(i);
    //                         colSets[c].add(i);
    //                         if (solve(a, r, c+1, rowSets, colSets)) {
    //                             return true;
    //                         }
    //                         a[r][c] = 0;
    //                         rowSets[r].remove(i);
    //                         colSets[c].remove(i);
    //                     }
    //                 } else if(r == N) {
    //                     if ((a[r][c+1] > i || a[r][c+1] == 0)&& (a[r-1][c] < i)) {
    //                         a[r][c] = i;
    //                         rowSets[r].add(i);
    //                         colSets[c].add(i);
    //                         if (solve(a, r, c+1, rowSets, colSets)) {
    //                             return true;
    //                         }
    //                         a[r][c] = 0;
    //                         rowSets[r].remove(i);
    //                         colSets[c].remove(i);
    //                     }
    //                 }
                    
    //             } else if(r == N) {
    //                 if (c == 0) {
    //                     if ((a[r][c+1] > i || a[r][c+1] == 0) && (a[r-1][c] < i)) {
    //                         a[r][c] = i;
    //                         rowSets[r].add(i);
    //                         colSets[c].add(i);
    //                         if (solve(a, r, c+1, rowSets, colSets)) {
    //                             return true;
    //                         }
    //                         a[r][c] = 0;
    //                         rowSets[r].remove(i);
    //                         colSets[c].remove(i);
    //                     }
    //                 } else if(c == N) {
    //                     if ((a[r][c-1] > i)&& (a[r-1][c] < i)) {
    //                         a[r][c] = i;
    //                         rowSets[r].add(i);
    //                         colSets[c].add(i);
    //                         if (solve(a, r, c+1, rowSets, colSets)) {
    //                             return true;
    //                         }
    //                         a[r][c] = 0;
    //                         rowSets[r].remove(i);
    //                         colSets[c].remove(i);
    //                     }
    //                 }
    //             }  else if (r == 0) {
    //                 if (c == 0) {
    //                     if ((a[r][c+1] > i || a[r][c+1] == 0) && (a[r+1][c] > i || a[r+1][c] == 0)) {
    //                         a[r][c] = i;
    //                         rowSets[r].add(i);
    //                         colSets[c].add(i);
    //                         if (solve(a, r, c+1, rowSets, colSets)) {
    //                             return true;
    //                         }
    //                         a[r][c] = 0;
    //                         rowSets[r].remove(i);
    //                         colSets[c].remove(i);
    //                     }
    //                 } else if(c == N) {
    //                     if ((a[r][c-1] > i)&& (a[r-1][c] < i)) {
    //                         a[r][c] = i;
    //                         rowSets[r].add(i);
    //                         colSets[c].add(i);
    //                         if (solve(a, r, c+1, rowSets, colSets)) {
    //                             return true;
    //                         }
    //                         a[r][c] = 0;
    //                         rowSets[r].remove(i);
    //                         colSets[c].remove(i);
    //                     }
    //                 }
    //             }  else {
    //                 if ((a[r][c+1] > i || a[r][c+1] == 0) && (a[r][c-1] < i) && (a[r+1][c] > i || a[r+1][c] == 0) && (a[r-1][c] < i)) {
    //                     a[r][c] = i;
    //                     rowSets[r].add(i);
    //                     colSets[c].add(i);
    //                     if (solve(a, r, c+1, rowSets, colSets)) {
    //                         return true;
    //                     }
    //                     a[r][c] = 0;
    //                     rowSets[r].remove(i);
    //                     colSets[c].remove(i);
    //                 }
    //             }
                
    //         }
    //     }

    //     return false;
    // }

    // static Boolean solve(int[][] a, int r, int c, Set<Integer>[] rowSets, Set<Integer>[] colSets) {
    //     if (c == M) {
    //         r++; c = 0;
    //         if (r == N) {
    //             for (int i = 0;i<N;i++) {
    //                 for (int j = 0;j<M;j++) {
    //                     System.out.print(a[i][j] + " ");
    //                 }
    //                 System.out.print("\n");
    //             }
    //             return true;
    //         }
    //     }
        

    //     if (a[r][c] != 0) {
    //         return solve(a, r, c+1, rowSets, colSets);
    //     }

    //     for (int i = 1;i<=100000000;i++) {
    //         if (!rowSets[r].contains(i) && !colSets[c].contains(i)) {
    //             if ((c+1 == M || a[r][c+1] > i || a[r][c+1] == 0) && (c-1 < 0 || a[r][c-1] < i) && (r+1 == N || a[r+1][c] > i || a[r+1][c] == 0) && (r-1 < 0 || a[r-1][c] < i)) {
    //                 a[r][c] = i;
    //                 rowSets[r].add(i);
    //                 colSets[c].add(i);
    //                 if (solve(a, r, c+1, rowSets, colSets)) {
    //                     return true;
    //                 }
    //                 a[r][c] = 0;
    //                 rowSets[r].remove(i);
    //                 colSets[c].remove(i);
    //             }
    //         }
    //     }

    //     return false;
    // }

    static Boolean solve(int[][] a, int r, int c) {
        if (c == M) {
            r++; c = 0;
            if (r == N) {
                for (int i = 0;i<N;i++) {
                    for (int j = 0;j<M;j++) {
                        System.out.print(a[i][j] + " ");
                    }
                    System.out.print("\n");
                }
                return true;
            }
        }
        

        if (a[r][c] != 0) {
            return solve(a, r, c+1);
        }

        for (int i = 1;i<=100000000;i++) {
            
            if ((c-1 < 0 || a[r][c-1] < i) && (r-1 < 0 || a[r-1][c] < i)) {
                a[r][c] = i;
                
                if (solve(a, r, c+1)) {
                    return true;
                }
                a[r][c] = 0;
                
            }
        }
        
        return false;
    }
    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}

