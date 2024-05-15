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

const int MM = 5002;
int N, T, K;
ll dist[MM];
bool vis[MM];
vector<pii> adj[MM];
vector<pii> pencils;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T;
    for(int i=1, x, y, z; i<=T; i++) {
        scan(x); scan(y); scan(z);
        adj[x].push_back({y, z});
    }
    cin >> K;
    for(int i=1, z, p; i<=K; i++) {
        scan(z); scan(p);
        pencils.push_back({z, p});
    }
    for (int i = 1;i<=N;i++) {
        int mDist = LLONG_MIN, u = -1;
        for (int j = 1;j<=N;j++) {
            if (!vis[j] && dist[j] < mDist) {
                mDist = dist[j]; u = j;
            }
        }
        if (u == -1) break;
        vis[u] = true;
        for (pii p:adj[u]) {
            if (p.second && dist[u] < dist[p.first]) {
                dist[p.first] = dist[u] + p.second;
            }
        }
    }
    ll ans = LONG_LONG_MAX;
    for (auto [f, s] : pencils) {
        ans = min(ans, dist[f] + s);
    }
    cout << ans << endl;
}