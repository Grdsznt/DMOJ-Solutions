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
ll N, Q, ls[MM], rs[MM], sum[MM], mx[MM], idx = 1;
//dynamically allocate nodes to the seg tree
void upd(ll l, ll r, ll pos, ll val, int n) {
    if (l == r) {sum[n] = mx[n] = val; return;}
    int mid = (l+r)/2;
    if (pos <= mid) {
        if (!ls[n]) ls[n] = ++idx;
        upd(l, mid, pos, val, ls[n]);
    } else {
        if (!rs[n]) rs[n] = ++idx;
        upd(mid+1, r, pos, val, rs[n]);
    }
    sum[n] = sum[ls[n]] + sum[rs[n]];
    mx[n] = max(mx[ls[n]], mx[rs[n]]);
}

ll qrySum(ll l, ll r, ll x, ll y, int n) {
    if (r < x || y < l || n == 0) return 0;
    if (x <= l && r <= y) return sum[n];
    ll mid = (l+r)/2;
    return qrySum(l, mid, x, y, ls[n]) + qrySum(mid+1, r, x, y, rs[n]);
}

ll qryMax(ll l, ll r, ll x, ll y, int n) {
    if (r < x || y < l || n == 0) return 0;
    if (x <= l && r <= y) return mx[n];
    ll mid = (l+r)/2;
    return max(qryMax(l, mid, x, y, ls[n]), qryMax(mid+1, r, x, y, rs[n]));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
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


