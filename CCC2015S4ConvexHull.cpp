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

const int MM = 2e3+3;
int k, n, m, A, B;
ll ans = INT_MAX, dist[MM][202];
struct qii {
    ll u, w, d;
    bool operator>(const qii &x) const {
        return w > x.w;
    }
};
vector<qii> adj[MM];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n >> m;
    for (int i = 0, a, b, t, h;i<m;i++) {
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }
    cin >> A >> B;

    for (int i = 0;i<MM;i++) {
        for (int j = 0;j<=200;j++) {
            dist[i][j] = INT_MAX;
        }
    }

    dist[A][0] = 0;

    priority_queue<qii, vector<qii>, greater<qii>> pq;
    pq.emplace(qii{A, 0, 0});
    while (!pq.empty()) {
        qii cur = pq.top(); pq.pop();
        if (cur.w > dist[cur.u][cur.d]) continue;
        for (qii nxt : adj[cur.u]) {
            if (nxt.d + cur.d >= k) continue; // if it breaks then no
            if (dist[nxt.u][nxt.d+cur.d] > cur.w + nxt.w) {
                dist[nxt.u][nxt.d+cur.d] = cur.w + nxt.w;
                pq.emplace(qii{nxt.u, dist[nxt.u][nxt.d+cur.d], cur.d+nxt.d});
            }
        }
    }
    for (int i = 0;i<=k;i++) {
        ans = min(ans, dist[B][i]);
    }
    cout << ((ans == INT_MAX) ? -1 : ans) << endl;
}
