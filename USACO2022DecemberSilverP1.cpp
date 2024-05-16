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

struct node {
    int u, v; ll h;
};

const int MM = 2e5+3;
int N, bales[MM]; ll diff[MM], avg = 0;
vector<int> adj[MM];
vector<node> ans;

void preprocess(int u, int pre) {
    diff[u] = bales[u] - avg;
    for (int v: adj[u]) {
        if (v != pre) {
            preprocess(v, u);
            diff[u] += diff[v];
        }
    }
}

void dfs(int u, int pre) {
    for (int v: adj[u]) {
        if (v != pre) {
            if (diff[v] >= 0) dfs(v, u);
            if (diff[v] > 0) ans.push_back({v, u, diff[v]});
        }
    }
    for (int v: adj[u]) {
        if (v != pre) {
            if (diff[v] < 0) {
                ans.push_back({u, v, -diff[v]});
                dfs(v, u);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1;i<=N;i++) {
        cin >> bales[i]; avg += bales[i];
    }
    for (int i = 1, x, y;i<N;i++) {
        cin >> x >> y; adj[x].push_back(y); adj[y].push_back(x);
    }
    avg /= N;

    preprocess(1, -1);
    dfs(1, -1);


    // start from largest weight
    cout << ans.size() << "\n";

    for (auto [u, v, h]: ans) cout << u << " "<< v << " " << h << endl;

}