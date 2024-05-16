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

int a[8][8], ans = INT_MIN;
vector<pii> sources;
int di[] = {1, 1, -1, -1}, dj[] = {1, -1, 1, -1};

void solve(int r, int c, int indx) {
    ans = max(ans, indx);
    for (int i = 0;i<4;i++) {
        int ni = r + 2*di[i], nj = c + 2*dj[i], mi = r + di[i], mj = c + dj[i];
        if (ni < 8 && ni >= 0 && nj < 8 && nj >= 0 && a[ni][nj] == 0 && a[mi][mj] == 2) {
            a[mi][mj] = 0;
            solve(ni, nj, indx + 1);
            a[mi][mj] = 2;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0;i<8;i++) {
        for (int j = 0;j<8;j++) {
            char c;
            cin >> c;
            if (c == 'A') {
                a[i][j] = 1;
                sources.push_back({i ,j});
            } else if (c == 'B') {
                a[i][j] = 2;
            }
        }
    }
    for (auto [f,s] : sources) {
        solve(f, s, 0);
    }

    cout << ans << endl;
}