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
int N;
vector<int> adj[MM], adj2[MM];
vector<pii> ans;

void dfs(int cur, int pre) {
    for (int v: adj[cur]) {
        if (v == pre) continue;
        adj2[pre].push_back(v);
        dfs(v, cur);
    }
}

void dfs2(int cur, int pre) {
    for (int v: adj2[cur]) {
        if (v == pre) continue;
        ans.push_back({cur, v});
        dfs2(v, cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1, u, v;i<N;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << 1 + adj[1].size() << "\n";
    dfs(1, 0); dfs2(1, 0);
    cout << ans.size() + 1 << "\n";
    for (auto[f, s]: ans) {
        cout << f << " " << s << endl;
    }
    ans.clear();
    for (int u: adj[1]) {
        dfs2(u, 0);
        cout << ans.size() + 1 << "\n";
        for (auto[f, s]: ans) {
            cout << f << " " << s << endl;
        }
        ans.clear();
    }

}
