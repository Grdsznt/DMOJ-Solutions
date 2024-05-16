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

const int MM = 1e6 + 2;
int N, Q, rnk[MM], p[MM], arr[MM];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void union1(int x, int y) {
    x = find(x); y = find(y);
    if (rnk[x] > rnk[y]) p[y] = x;
    else p[x] = y;
    rnk[y] += (rnk[x] == rnk[y]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;


    for (int i = 1;i<=N;i++) {
        cin >> arr[i];
        p[i] = i;
    }

    for (int i = 0, a, b;i<Q;i++) {
        int x; cin >> x;
        if (x == 1) {
            cin >> a >> b;
            union1(a, b);
        } else if (x == 2) {
            cin >> a; int par = find(a), ans = 0;
            for (int j = 1;j<=N;j++) {
                if (p[j] == par) ans++;
            }
            cout << ans << endl;
        } else {
            cin >> a; int par = find(a); ll ans = 0;
            for (int j = 1;j<=N;j++) {
                if (p[j] == par) ans += arr[j];
            }
            cout << ans << endl;
        }

    }

}