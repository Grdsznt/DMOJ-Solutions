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

const int MM = 2e5+3;
int N, M;
bool vis[MM];
vector<int> adj[51];
vector<pii> edges;

bool bfs(int source, int destination) {
    memset(vis, 0, sizeof(vis)); queue<int> q;
    q.push(source); vis[source] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == destination) return true;
        for (int v: adj[u]) {
            if (!vis[v]) {q.push(v); vis[v] = 1;}
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1, x, y;i<=M;i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        edges.push_back({x, y});
    }

    for (int i = 1;i<=M;i++) {
        auto [f,s] = edges[i-1];
        for (int j = 0; j < adj[f].size();j++) {
            if (adj[f][j] == s) {
                adj[f].erase(adj[f].begin()+ j);
            }
        }
        if (bfs(1, N)) cout << "YES" << endl;
        else {cout << "NO" << endl;}
        adj[f].push_back(s);
    }



}
