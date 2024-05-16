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

const int MM = 1e5+4;

int N, M, ans = 0, a[MM];

struct node {
    int l, r, v;
};

node seg[4*MM];

void build(int l, int r, int n) {
    seg[n].l = l; seg[n].r = r;
    if (l == r) {
        seg[n].v = a[l]; return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*n);
    build(mid+1, r, 2*n+1);
    seg[n].v = min(seg[2*n].v, seg[2*n+1].v);
}

void upd(int pos, int val, int n) {
    if (seg[n].l == pos && seg[n].r == pos) {
        seg[n].v = val; return;
    }
    int mid = (seg[n].l + seg[n].r)/2;
    if (pos<=mid) upd(pos, val, 2*n);
    else upd(pos, val, 2*n+1);
    seg[n].v = min(seg[2*n].v, seg[2*n+1].v);
}

int qry(int l, int r, int n) {
    if (seg[n].l == l && seg[n].r == r) return seg[n].v;
    int mid = (seg[n].l+seg[n].r)/2;
    if (r <= mid) return qry(l, r, 2 * n);
    else if (l > mid) return qry(l, r, 2 * n + 1);
    else return min(qry(l, mid, 2*n), qry(mid+1, r, 2*n+1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0;i<N;i++){
        cin >> a[i];
    }
    build(0, N-1, 1);
    for (int i = 0;i<M;i++) {
        char c; cin >> c;
        if (c == 'M') {
            int j, x; cin >> j >> x;
            upd(j, x, 1);
        } else {
            int j, k; cin >> j >> k;
            cout << qry(j, k, 1) << endl;
        }
    }
}