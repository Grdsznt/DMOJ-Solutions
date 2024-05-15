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

int in[8];
vector<int> adj[8];
vector<int> topSort;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    adj[1].push_back(7); in[7]++;
    adj[1].push_back(4); in[4]++;
    adj[2].push_back(1); in[1]++;
    adj[3].push_back(4); in[4]++;
    adj[3].push_back(5); in[5]++;


    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        adj[x].push_back(y); in[y]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1;i<=7;i++) {
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.top(); q.pop();
        topSort.push_back(u);
        for (int v: adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                 q.push(v);
            }
        }
    }

    if (topSort.size() == 7) {
        for (int v: topSort) {
            cout << v << " ";
        }
        cout << "\n";
    } else {
        cout << "Cannot complete these tasks. Going to bed." << "\n";
    }


}
