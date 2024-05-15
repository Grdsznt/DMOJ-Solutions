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

const int MM = 2e3 + 2;
int x[MM], y[MM], dp[MM], dist[MM], tmp[MM];
ll n, k, other;

vector<array<int, 3>> vec;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1;i<=n;i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0;i<=n;i++) {
        for (int j = i+1;j<= n;j++) {
            int d = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
            vec.push_back({d, i, j});
        }
    }
    sort(vec.begin(), vec.end());
    for (auto [d, u, v] : vec) {
        if (d>dist[u]) {
            tmp[u] = dp[u]; dist[u] = d;
        }
        if (d>dist[v]) {
            tmp[v] = dp[v]; dist[v] = d;
        }
        if (u == 0) {
            dp[u] = max(dp[u], tmp[v] + 1);
        }
        else {
            dp[u] = max(dp[u], tmp[v] + 1);
            dp[v] = max(dp[v], tmp[u] + 1);
        }
    }
    cout << dp[0] << endl;

}

