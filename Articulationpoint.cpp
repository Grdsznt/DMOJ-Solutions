#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e6+3;
int N, M, dfn[MM], low[MM], indx = 0;
vector<int> adj[MM];
set<int> st;


void tarjan(int cur, int pre) {
    dfn[cur] = low[cur] = ++indx; int cnt = 0;
    for (int v: adj[cur]) {
        if (v == pre) continue;
        if (dfn[v] == 0) {
            tarjan(v, cur); cnt++;
            low[cur] = min(low[cur], low[v]);
            if (pre != -1 && low[v] >= dfn[cur]) st.insert(cur);
        } else {
            low[cur] = min(low[cur], dfn[v]);
        }
    }
    if (pre == -1 && cnt > 1) st.insert(cur);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0, x, y;i<M;i++) {
        cin >> x >> y; adj[x].push_back(y); adj[y].push_back(x);
    }
    for (int i = 1;i<=N;i++) {
        if (dfn[i] == 0) tarjan(i, -1);
    }
    cout << st.size() << "\n";

}
