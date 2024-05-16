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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 1e5+2;
int n, m;
ll sDist[MM], eDist[MM], ans = LLONG_MIN;
bool vis[MM];
vector<pii> adj[MM];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0, a, b, x;i<m;i++) {
        cin >> a >> b >> x;
        adj[a].push_back({x,b});
        adj[b].push_back({x,a});
    }
    for (int i = 0;i<n;i++) {
        if (i > 0) sDist[i] = LLONG_MAX;
        if (i < n-1) eDist[i] = LLONG_MAX;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [w, v] : adj[u]) {
            if (sDist[v] > sDist[u] + w) {
                sDist[v] = sDist[u] + w;
                pq.push({sDist[v], v});
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    pq.push({0, n-1});
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [w, v] : adj[u]) {
            if (eDist[v] > eDist[u] + w) {
                eDist[v] = eDist[u] + w;
                pq.push({eDist[v], v});
            }
        }
    }

    for (int i = 0;i<n;i++) {
        ans = max(sDist[i] + eDist[i], ans);
    }

    cout << ans << "\n";
}

