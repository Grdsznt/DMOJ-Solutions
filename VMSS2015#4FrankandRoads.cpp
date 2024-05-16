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

const int MM = 2e3+2;
int T, N, M, G, fb[MM];
ll dist[MM], ans = 0;
bool vis[MM];
vector<pii> adj[MM];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T >> N >> M >> G;
    for (int i = 0;i<G;i++) {
        cin >> fb[i];
    }
    for (int i = 0, a, b, l;i<M;i++) {
        cin >> a >> b >> l;
        adj[a].push_back({l, b});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
//    dist[0] = 0;
    for (int i = 1;i<=N;i++) {
        dist[i] = LLONG_MAX;
    }
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [w, v] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0;i<G;i++) {
        if(dist[fb[i]] < T)  {
            ans++;
        }
    }

    cout << ans << "\n";
}

