#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"



struct frac {
    ll x, y;
    bool operator < (const frac & o) const {return x*o.y < o.x *y;}
};

const int MM = 1e6+3;
int n, a[MM], dist1[MM], dist2[MM];
vector<int> adj[MM];
frac ans = frac{(ll) 1e18, 1};

void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        if (a[v] != 1) continue; // want to find nodes with value 1
        if (dist1[v] + 1 > dist1[u]) { // udpate distance
            dist2[u] = dist1[u]; dist1[u] = dist1[v] + 1;
        } else if (dist1[v] + 1 > dist2[u]) dist2[u] = dist1[v] + 1;
    }
}

void dfs2(int u,int par,int plen) {
    ans = min(ans, frac{a[u],dist1[u] + max(dist2[u], plen) + 1});
    for (int v:adj[u]) {
        if (v == par) continue;
        int newplen = 0;
        if (a[u] == 1) {
            if (a[v] == 1 && dist1[v] + 1 == dist1[u]) newplen = max(plen, dist2[u]) + 1;
            else newplen = max(plen, dist1[u]) + 1;
        }
        dfs2(v, u, newplen);
    }
}
// second dfs reroots the tree to get min magic val
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0, x, y;i<n-1;i++) {
        cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }

    for (int i = 1;i<=n;i++) {
        cin >> a[i]; ans = min(ans, frac{a[i], 1});
    }
    dfs(1, 0);
    dfs2(1, 0, 0);
    ll g = gcd(ans.x, ans.y); // just to simplify fraction to lowest terms
    cout << ans.x/g << " / " << ans.y/g << "\n";
}


