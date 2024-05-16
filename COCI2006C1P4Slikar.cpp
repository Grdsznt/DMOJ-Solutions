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
//#define si set<int>
#define sc set<char>


#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"


const int MM = 55;
int r, c, a[MM][MM], si, sj, ei, ej, dist[MM][MM], dist2[MM][MM];
bool vis[MM][MM];
//lazy propagation
int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c; queue<pii> q;
    for (int i = 0;i<r;i++) {
        for (int j = 0;j<c;j++) {
            char ch; cin >> ch;
            if (ch == 'X') a[i][j] = 1;
            else if (ch == 'D') {ei = i; ej = j;}
            else if (ch == 'S') {si = i; sj = j;}
            else if (ch == '*') {a[i][j] = 2; q.push({i, j});}
        }
    }

    while (!q.empty()) {
        auto [f, s] = q.front(); q.pop();
        for (int i = 0;i<4;i++) {
            int ni = f + di[i]; int nj = s + dj[i];
            if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                if (!vis[ni][nj] && a[ni][nj] != 1) {
                    q.push({ni, nj}); vis[ni][nj] = true;
                    dist[ni][nj] = dist[f][s] + 1;
                }
            }
        }
    }

    memset(vis, false, sizeof(vis));

    vis[si][sj] = true;
    q.push({si, sj});

    while (!q.empty()) {
        auto [f, s] = q.front(); q.pop();
        if (f == ei && s == ej) break;
        for (int i = 0;i<4;i++) {
            int ni = f + di[i]; int nj = s + dj[i];
            if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                if (!vis[ni][nj] && a[ni][nj] != 1) {
                    dist2[ni][nj] = dist2[f][s] + 1;
                    if (dist2[ni][nj] < dist[ni][nj]) {
                        q.push({ni, nj}); vis[ni][nj] = true;
                    }
                }
            }
        }
    }

    if (dist[ei][ej] != 0) cout << dist[ei][ej] << "\n";
    else cout << "KAKTUS\n";


}