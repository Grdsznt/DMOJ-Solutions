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

const int MM = 5e5+2;
int n, m, d;
ll sDist[MM], eDist[MM], ans = LLONG_MAX;
bool vis[MM];
vector<pair<int, pii>> v;
vector<pii> adj[MM], adj2[MM];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0, a, b, k;i<m;i++) {
        cin >> a >> b >> k;
        adj[a].push_back({k,b});
        adj2[b].push_back({k, a});
    }
    cin >> d;
    for (int i = 0, a, b, g;i<d;i++) {
        cin >> a >> b >> g;
        v.push_back({a, {b, g}});
    }
    for (int i = 1;i<=n;i++) {
        sDist[i] = LLONG_MAX; eDist[i] = LLONG_MAX;
    }
    sDist[1] = 0; eDist[n] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
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
    pq.push({0, n});
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [w, v] : adj2[u]) {
            if (eDist[v] > eDist[u] + w) {
                eDist[v] = eDist[u] + w;
                pq.push({eDist[v], v});
            }
        }
    }
    ans = min(sDist[n], eDist[1]);
    for (pair<int, pii> p: v) {
        ans = min(sDist[p.first] + p.second.second + eDist[p.second.first], ans);
    }

    cout << ans << "\n";
}

