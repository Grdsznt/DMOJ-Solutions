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

const int MM = 1e5 + 2;
int N, p[MM], rnk[MM];

bool has[MM];

unordered_map<string, int> mp;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void union1(int x, int y) {
    x = find(x); y = find(y);
    if (rnk[x] > rnk[y]) p[y] = x;
    else p[x] = y; rnk[y] += (rnk[x] == rnk[y]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int T = 0;T<5;T++) {
        cin >> N;
        for (int i = 1;i<MM;i++) {
            p[i] = i;
        }
        for (int i = 0;i<N;i++) {
            char c; string a, b;
            cin >> c >> a >> b;
            if (c == 'p') {
                if (mp.find(a) == mp.end()) {
                    mp[a] = mp.size();
                }
                if (mp.find(b) == mp.end()) {
                    mp[b] = mp.size();
                }
                union1(mp[a], mp[b]);
                has[mp[a]] = true;
                has[mp[b]] = true;
            } else {
                if (find(mp[a]) == find(mp[b]) && has[mp[a]]) cout << "connected\n";
                else cout << "not connected\n";
            }
        }
    }
}