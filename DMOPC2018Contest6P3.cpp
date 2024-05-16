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
int N, M, rnk[MM], p[MM], cyc = 0;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void union1(int x, int y) {
    x = find(x); y = find(y);
    if (rnk[x] > rnk[y]) p[y] = x;
    else p[x] = y; rnk[y] += rnk[x] == rnk[y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1;i<=N;i++) {
        p[i] = i; rnk[i] = 0;
    }

    for (int i = 0,a,b;i<M;i++) {
        cin >> a >> b;
        if (find(a) == find(b)) cyc++;
        union1(a,b);
    }

    if (cyc <= 1) cout << "YES\n";
    else cout << "NO\n";
}