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


const int MM = 1e3+4;

int N, M, K, S, T, ans = 0, pre, last;
bool usable[MM];
unordered_set<int> adj[MM]; bool vis[MM];
vector<array<int, 4>> edge;

void dfs(int st) {

    vis[st] = true;
    for (int v: adj[st]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    cin >> S >> T;

    for (int i = 0, a, b, c, d;i<M;i++) {
        cin >> a >> b >> c >> d;
        edge.push_back({c, 0, a, b}); edge.push_back({d+1, 1, a, b});
    }
    sort(edge.begin(), edge.end());
    for (auto [cur, enable, a, b] : edge) {
        if (enable == 0) adj[a].insert(b);
        else adj[a].erase(b);
        dfs(S);

        if (vis[T]) {
            ans += (pre ? cur-last : 1);
        } else if (pre){
            ans += cur - last - 1;
        }
        last = cur; pre = vis[T];
        memset(vis, 0, sizeof(vis));
    }

    cout << ans << "\n";
}
