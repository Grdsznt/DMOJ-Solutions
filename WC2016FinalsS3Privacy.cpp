#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>


#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 403;
int N, K, a[MM], dp[MM][MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K; K++;
    for (int i = 1;i<=N;i++) cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
//    for (int i = 1;i<=400;i++) {
//        for (int j = 1;j<=400;j++) {
//            dp[i][j] = INT_MAX;
//        }
//    }
    dp[0][0] = 0;
    for (int i = 1;i<=N;i++) {
        for (int j = i-1; j>=0;j--) {
            int cost = 0, div = i-j-1;
            for (int k = j+1;k<=i;k++) {
                if (a[k] < div) cost += div-a[k];
            }
            for (int k = 1;k<=K;k++) {
                dp[i][k] = min(dp[i][k], dp[j][k-1] + cost);
            }
        }
//        for (int j = 0; j<=K;j++) {
//            int cost = max(0, a[i-1] - j);
//            dp[i][j] = min(dp[i][j], dp[i-1][j] + cost);
//            if (j>0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
//        }
    }

    cout << dp[N][K] << endl;
}
