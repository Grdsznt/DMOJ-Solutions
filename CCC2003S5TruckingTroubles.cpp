//#include <bits/stdc++.h>
//#include <iostream>
//using namespace std;
//
///* TYPES  */
//#define ll long long
//#define pii pair<int, int>
//#define pll pair<long long, long long>
//#define vi vector<int>
//#define vll vector<long long>
//#define mii map<int, int>
//#define si set<int>
//#define sc set<char>
//
//#pragma GCC optimize "Ofast"
//#pragma GCC target "avx2"
//
//const int MM = 1e4 + 2;
//int C, R, D, rnk[MM], p[MM], d[MM], dist[MM], ans = INT_MAX;
//
//struct edge {
//    int u, v, w;
//    bool operator<(edge const& other) {
//        return w > other.w;
//    }
//};
//vector<pii> adj[MM];
//vector<edge> edges;
//
//int find(int x) {
//    if (p[x] != x) p[x] = find(p[x]);
//    return p[x];
//}
//
//void union1(int x, int y) {
//    x = find(x); y = find(y);
//    if (rnk[x] > rnk[y]) p[y] = x;
//    else p[x] = y;
//    rnk[y] += (rnk[x] == rnk[y]);
//}
//
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> C >> R >> D;
//
//
//    for (int i = 1;i<=C;i++) {
//        p[i] = i;
//    }
//
//    for (int i = 0, a, b, c;i<R;i++) {
//        cin >> a >> b >> c;
//        edges.push_back({a, b, c});
//        adj[a].push_back({b, c});
//        adj[b].push_back({a, c});
//    }
//
//    for (int i = 0, x;i<D;i++) {
//        cin >> x; d[x] = 1;
//    }
//
//    sort(edges.begin(), edges.end());
//
//    for (edge e: edges) {
//        if (find(e.u) != find(e.v)) {
//            union1(e.u, e.v);
//            dist[e.v] = dist[e.u] + e.w;
//        }
//    }
//
//    for (int i = 0;i<D;i++) {
//        if (d[i] == 1) {
//            ans = min(dist[i], ans);
//        }
//    }
//
//    cout << ans << endl;
//
//}

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int MM = 1e4 + 2;
vector<pii> adj[MM];
int C, R, D, dist[MM], ans = INT_MAX;

void dijkstra() {
    priority_queue<pii> pq;
    memset(dist, 0, sizeof(dist));
    dist[1] = INT_MAX;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int curr_weight = pq.top().first;
        pq.pop();

        for (pii p : adj[u]) {
            int v = p.first, weight = p.second;
            int path_weight = min(curr_weight, weight);
            if (path_weight > dist[v]) {
                dist[v] = path_weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> R >> D;
    for (int i = 0, a, b, c; i < R; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijkstra();

    for (int i = 0, x; i < D; i++) {
        cin >> x;
        ans = min(dist[x], ans);
    }

    cout << ans << endl;
}
