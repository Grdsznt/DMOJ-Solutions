#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

//const int MM = 1e5+3;
//int N, a[MM], b[MM], first[MM], dp[MM];
//
//vector<pii> rit, lft, seg;
//
//int main(){
//    ios::sync_with_stdio(0); cin.tie(0);
//    cin >> N;
//    for (int i = 1;i<=N;i++) cin >> a[i];
//    dp[1] = 0;
//    // dp will be minimum cost to buy items up to an i
//    for (int i = 1;i<=N;i++) {
//        for (int j = 1;i<=K;j++) {
//            a[i-1] = dp[i]
//        }
//    }
//}

const int MM = 1e4+3;
int N, C, K, ans, val[MM], weight[MM]; vector<pii> adj[MM];
// Tree's dfs
void dfs(int u, int par, int last) {
    weight[u] = last;
    for (auto[v, w]: adj[u]) {
        if (v==par) continue;
        dfs(v, u, w);
        val[u] += val[v];
        weight[u] += weight[v];
    }
    if (val[u] >= C && weight[u] <= K) ans++;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C >> K;
    for (int i = 1;i<=N;i++) cin >> val[i];
    for (int i = 1, u, v, w;i<N;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    dfs(1, 0, K+1);
    cout << ans << "\n";
}

