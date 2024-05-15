#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e5+3;
int n, dp[MM];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1, x;i<=n;i++) {
        cin >> x;
        for (int j = x;j<=n;j++) dp[j] = min(dp[j], 1 + dp[j-x]);
    }
    if (dp[n] > n) cout << "Roberta acknowledges defeat.\n";
    else cout << "Roberta wins in " << n << " strokes.\n";
}

