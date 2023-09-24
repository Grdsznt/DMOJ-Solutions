import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class recurseexample {
    static int count;
    static long[] memo = new long[100];
  static int gcd(int a, int b) {
    int remainder = a % b;
    a = b;
    b = remainder;
    if (b != 0) {
      return gcd(a, b);
    } else {
      return a;
    }
  }

  public static void main(String[] args) {
    System.out.println(gcd(30, 18));
    System.out.println(power(2, 2));
    System.out.println(factorial(5));
    System.out.println("lcm of 30 and  18: " + 18*30/gcd(30, 18));
    System.out.println(fibonacci(50));
    hanoi(7, 'A', 'B', 'C');
  }

  static int power(int x, int n) {
    if (n == 1) {
      return x;
    }else {
      return x * power(x, n - 1);
    }
  }

  static int factorial(int n) {
    if (n == 1) return 1;
    else {
      return n * factorial(n - 1);
    }
  }

  static long fibonacci(int x) {
    if (memo[x]!=0) return memo[x];
    if (x <= 2) {
        return memo[x] = 1;
    }
    return memo[x] = fibonacci(x-1) + fibonacci(x-2);
    

  }

  static void hanoi(int n, char A, char B, char C) {

    if (n == 1) {
        System.out.println(A + "--->" + C);
        count++;
        System.out.println(count);
        return;
    }
    hanoi(n-1, A, C, B);
    System.out.println(A + "--->" + C);
    hanoi(n-1, B, A, C);
    count++;

  }


}


class countapples {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static void count (int prev, int sum, String sol,int n) {

        if (sum == n) {
            System.out.println(sol);
            
        } else {
            for (int i = 0;i<(n-sum+1)-prev; i++) {
            count(i, sum+i, sol + "+" + i, n);
            }
        }
        
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        int n = Integer.parseInt(br.readLine());
        for (int k = 0; k < n/2+1; k++) {
            count(k, k, Integer.toString(n) + "=" + Integer.toString(k), n);    
        }
        
    }
    
}

class CCC2005J5 {

    static String Aword(String word) {
        return word;
    }

    static String MonkeyWord(String word) {
        return word;
    }
}