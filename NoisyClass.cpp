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


const int MM = 2e4+3;
int N, M, in[MM], num = 0;
vector<int> adj[MM];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1, x, y;i<=M;i++) {
        cin >> x >> y; adj[x].push_back(y);
        in[y]++;

    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1;i<=N;i++) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.top(); q.pop();
        num++;
        for (int v: adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    if (num == N) cout << "Y" << "\n";
    else cout << "N" << "\n";


}
