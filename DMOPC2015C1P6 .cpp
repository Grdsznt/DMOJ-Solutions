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


const int MM = 3e7;
int M, N, Q, a[MM], sum[4*MM], lz[4*MM];
//lazy propagation
void pd(int l, int r, int n) {
    int val = lz[n], mid = (l+r)/2, lc = 2*n, rc = 2*n+1;
    sum[lc] = (sum[lc] + (ll) (mid-l+1) *val %M) %M; lz[lc] = (lz[lc] + val) %M;
    sum[rc] = (sum[rc] + (ll) (mid-l+1) *val %M) %M; lz[lc] = (lz[lc] + val) %M;
}
void build(int l, int r, int n) {
    if (l == r) {
        sum[n] = a[l]; return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*n); build(mid+1, r, 2*n+1);
    sum[n] = (sum[2*n] + sum[2*n+1])%M;
}
void upd(int l, int r, int x, int y, int val, int n) {
    if (l == x && r == y) {sum[n] = (sum[n] + (ll) (r-l+1)*val%M)%M; return;}
    if (lz[n]) pd(l, r, n);
    int mid = (l+r)/2;
    if (y <= mid) {
        upd(l, mid, x, y, val, 2*n);
    } else if (x > mid){
        upd(mid+1, r, x, y, val, 2*n+1);
    } else {
        upd(l, mid, x, mid, val, 2*n); upd(mid+1, r, mid+1, y,val, 2*n+1);
    }
    sum[n] = (sum[2*n] + sum[2*n+1]) %M;
}

int qry (int l, int r, int x, int y, int n) {
    if (r < x || l > y) return 0;
    if (x <= l && r <= y) return sum[n];
    if (lz[n])  pd(l, r, n);
    int mid = (l+r)/2;
    return (qry(l, mid, x, y, 2*n) + qry(mid+1, r, x, y, 2*n+1))%M;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> Q;
    ll lastAns = 0;
    for (int i = 0;i<Q;i++) {
        char c; cin >> c    ;
        if (c == 'C') {
            ll x, v; cin >> x >> v; x ^= lastAns; v ^= lastAns;
            upd(1, N, x, v, 1);
        } else if (c == 'S') {
            ll l, r; cin >> l >> r; l ^= lastAns; r ^= lastAns;
            ll ans = qrySum(1, N, l, r, 1);
            lastAns = ans; cout << ans << endl;
        } else {
            int l, r; cin >> l >> r; l ^= lastAns; r ^= lastAns;
            ll ans = qryMax(1, N, l, r, 1);
            lastAns = ans; cout << ans << endl;
        }
    }

}


