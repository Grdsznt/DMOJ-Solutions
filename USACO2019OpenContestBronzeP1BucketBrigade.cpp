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

int grid[10][10], di[] = {0, -1, 0, 1}, dj[] = {1, 0, -1, 0}, sti, stj, ei, ej;

bool vis[10][10];
int dist[10][10];

bool valid (int i, int j) {
    if (i < 10 && i >= 0 && j < 10 && j >= 0 && !vis[i][j] && grid[i][j] != 1) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0;i<10;i++) {
        for (int j = 0;j<10;j++) {
            char c; cin >> c;
            if (c == 'B') {
                ei = i; ej = j;
            } else if (c == 'L') {
                sti = i; stj = j;
            } else if (c == 'R') {
                grid[i][j] = 1;
            }
        }
    }

    queue<pii> q; vis[sti][stj] = true;
    q.push({sti, stj});
    dist[sti][stj] = 0;
    while (!q.empty()) {
        auto [f, s] = q.front(); q.pop();
        if (f == ei && s == ej) break;
        for (int i = 0;i<4;i++) {
            int ni = f + di[i], nj = s + dj[i];
            if (valid(ni, nj)) {
                q.push({ni, nj}); vis[ni][nj] = true;
                dist[ni][nj] = dist[f][s] + 1;
            }
        }
    }

    cout << dist[ei][ej]-1 << endl;

}