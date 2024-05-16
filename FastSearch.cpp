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

const int MM = 1e6+3;
int N, Q, a[MM];
ll st[4*MM];

void upd(int pos, int val, int l, int r, int n) {
    if (l == r) {st[n] = val; return;}
    int mid = (l+r)/2;
    if (pos <= mid) upd(pos, val, l, mid, 2*n);
    else upd(pos, val, mid+1, r, 2*n+1);
    st[n] = min(st[2*n], st[2*n+1]);
}

void build(int l, int r, int n) {
    if (l == r) {st[n] = a[l]; return;}
    int mid = (l+r)/2;
    build(l, mid, 2*n); build(mid+1, r, 2*n+1);
    st[n] = min(st[2*n], st[2*n+1]);
}

int qry(int l, int r, int k, int x, int y, int n) {
//    if (l == r) return l;
    if (y < l || x > r || st[n] >= k) {
        return -1;
    }
    if (x == y) {
        return x;
    }
    int mid = (x+y)/2;
    int lft = qry(l, r, k, x, mid, 2*n);
    if (lft != -1) {
        return lft;
    }
    return qry(l, r, k, mid+1, y, 2*n+1);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q; int lastAns = 0;
    for(int i = 1;i<=N;i++) cin >> a[i];
    build(1, N, 1);
    for (int i = 0, op;i<Q;i++) {
        cin >> op;
        if (op == 1) {
            int p, x; cin >> p >> x; p ^= lastAns; x ^= lastAns;
            upd(p, x, 1, N, 1);
        } else {
            int l, r, k; cin >> l >> r >> k;
            l ^= lastAns; r ^= lastAns; k ^= lastAns;
            lastAns = qry(l, r, k, 1, N, 1);
            cout << lastAns << "\n";
        }
    }

}