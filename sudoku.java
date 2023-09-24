import java.util.*;
import java.io.*;

public class sudoku {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[][] board = new int[9][9];
    public static void main(String[] args) throws NumberFormatException, IOException {
        for (int i = 0;i<9;i++) {
            for (int j = 0;j<9;j++) {
                String character = br.readLine();
                for (int k = 0;k<character.length();k++) {
                    if (character.substring(k).contains(".")) {
                        board[i][j] = 0;
                    } else {
                        board[i][j] = Integer.parseInt(character);
                    }
                }
            }
        }
        solve(board, 0, 0);
        for (int l = 0;l<9;l++) {
            for(int m = 0;m<9;m++) {
                System.out.print(board[l][m]);
            }
            System.out.print("\n");
        }
    }

    static boolean solve(int[][] board, int row, int col) {
        if (col == 9) {
            row++;
            col = 0;
        }
        
        if (row == 9) {
            return true;
        }
        
        if (board[row][col] != 0) {
            return solve(board, row, col + 1);
        }
        
        for (int c = 1; c <= 9; c++) {
            if (valid(board, row, col, c)) {
                board[row][col] = c;
                if (solve(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = 0;
            }
        }
        
        return false;
    }

    static boolean valid(int[][] board, int row, int col, int n) {
        for (int i = 0;i<9;i++) {
            if (board[row][i] == n) {
                return false;
            } else if(board[i][col] == n) {
                return false;
            }  

            int row3 = (row / 3) * 3 + i / 3;
            int col3 = (col / 3) * 3 + i % 3;
            if (board[row3][col3] == n) {
                return false;
            }
        }
        return true;
    }

    static String next () throws IOException {
        while (st == null || ! st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
