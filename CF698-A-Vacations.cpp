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

const int MM = 1e2+5;

int n, a[MM], dp[MM][3];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1;i<=n;i++) cin >> a[i];

    for (int i = 1;i<=n;i++) {
        for (int j = 0;j<3;j++)
            dp[i][j] = INT_MAX;
    }

    dp[n][0] = (a[n] == 0) ? 1 : 0;
    dp[n][1] = (a[n] == 0 || a[n] == 1) ? 1 : 0;
    dp[n][2] = (a[n] == 0 || a[n] == 2) ? 1 : 0;
    for (int i = n-1; i >= 1;i--) {
        if (a[i] == 0) {
            dp[i][0] = dp[i+1][0] + 1;
            dp[i][1] = dp[i+1][0] + 1;
            dp[i][2] = dp[i+1][0] + 1;
        }
        if (a[i] == 1) {
            dp[i][0] = min(dp[i+1][1], dp[i+1][0] + 1);
            dp[i][1] = dp[i+1][0] + 1;
            dp[i][2] = min(dp[i+1][1], dp[i+1][0] + 1);
        }
        if(a[i] == 2){
            dp[i][0] = min(dp[i+1][2], dp[i+1][0] + 1);
            dp[i][1] = min(dp[i+1][2], dp[i+1][0] + 1);
            dp[i][2] = dp[i+1][0] + 1;
        }
        if(a[i] == 3) {
            dp[i][0] = min({dp[i+1][1], dp[i+1][2], dp[i+1][0] + 1});
            dp[i][1] = min(dp[i+1][2], dp[i+1][0] + 1);
            dp[i][2] = min(dp[i+1][1], dp[i+1][0] + 1);
        }
    }

    cout << dp[1][0] << "\n";
}

