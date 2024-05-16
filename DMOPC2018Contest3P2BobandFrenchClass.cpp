#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e5+3;
int n, dp[MM][2],f[MM], e[MM];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1;i<=n;i++) cin >> f[i];
    for (int i = 1;i<=n;i++) cin >> e[i];
    // dp[i][0] max pts for first i words in eng (0) or french (1)
    dp[1][0] = e[1]; dp[1][1] = f[1];
    for (int i = 2;i<=n;i++) {
        dp[i][0] = e[i] + max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(f[i] + dp[i-1][0], f[i]+f[i-1] + dp[i-2][0]);
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
}

for (int i = 1, x;i<=n;i++) {
    cin >> x;
    for (int j = x;j<=n;j++) dp[j] = min(dp[j], 1 + dp[j-x]);
}
if (dp[n] > n) cout << "Roberta acknowledges defeat.\n";
else cout "Roberta wins in " + n + " strokes.\n";