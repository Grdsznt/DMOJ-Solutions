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


const int MM = 2e5+2;
int N, in[MM];
vector<int> adj[MM];
vector<int> topSort;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1, C;i<=N;i++) {
        cin >> C;
        for (int j = 0, x;j<C;j++) {
            cin >> x; adj[x].push_back(i);
            in[i]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1;i<=N;i++) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.top(); q.pop();
        cout << u << " ";
        topSort.push_back(u);
        for (int v: adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << "\n";


}
