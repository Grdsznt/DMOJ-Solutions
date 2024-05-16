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
int N, M, K, rnk[MM], p[MM], t[MM], ans = 0;

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

    cin >> N >> M >> K;


    for (int i = 1;i<=N;i++) {
        char c; cin >> c;
        if (c == 'P') {
            t[i] = 1;
        } else if (c == 'Z') {
            t[i] = 2;
        }
        p[i] = i;
    }

    for (int i = 0, a, b;i<M;i++) {
        cin >> a >> b;
        if (t[a] == t[b]) union1(a, b);
    }

    for (int i = 0, x, y;i<K;i++) {
        cin >> x >> y;
        if (find(x) == find(y)) {
            ans++;
        }
    }

    cout << ans << endl;

}