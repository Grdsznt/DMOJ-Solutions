
#include <bits/stdc++.h>
using namespace std;

int factors[100001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int j = 1;j<=100000;j++) {
        
        for (int k = 1;k<=sqrt(j);k++) {
            
            if (j % k == 0 && k*k != j) {factors[j] += 2;}
            else if (k*k == j) {factors[j]++;}
        }
    }
    
    int i; scanf("%d", &i);

    for (i; i > 0;i--) {
        int K, A, B, ans = 0;
        scanf("%d%d%d", &K, &A, &B);

        
        for (int j = A;j<=B;j++) {
            if ((factors[j]) == K) ans++;
        }
        printf("%d\n", ans);
    }
}
        