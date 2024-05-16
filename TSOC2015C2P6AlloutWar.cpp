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


const int MM = 1e6+2;
int N, Q; ll st[4*MM], lz[4*MM];
//lazy propagation
void pd(int n) {
    st[2*n] = max(0LL, st[2*n] - lz[n]); lz[2*n] += lz[n]; // left child
    st[2*n+1] = max(0LL, st[2*n+1] - lz[n]); lz[2*n+1] += lz[n]; // right child
    lz[n] = 0; // clear it
}
void build(int l, int r, int n) {
    if (l == r) {
        cin >> st[n]; lz[n] = 0; return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*n); build(mid+1, r, 2*n+1);
    st[n] = min(st[2*n], st[2*n+1]);
}
void upd(int l, int r, int x, int y, int val, int n) {
    if (l == x && r == y) { st[n] = max(0LL, st[n]-val); lz[n] += val; return;}
    if (lz[n]) pd(n);
    int mid = (l+r)/2;
    if (y <= mid) {
        upd(l, mid, x, y, val, 2*n);
    } else if (x > mid){
        upd(mid+1, r, x, y, val, 2*n+1);
    } else {
        upd(l, mid, x, mid, val, 2*n); upd(mid+1, r, mid+1, y,val, 2*n+1);
    }
    st[n] = min(st[2*n], st[2*n+1]); // pushup
}

int qry (int l, int r, int x, int y, int n) {
    if (x == l && r == y) return st[n];
    if (lz[n])  pd(n);
    int mid = (l+r)/2;
    if (y <= mid) {
        return qry(l, mid, x, y, 2*n);
    } else if (x > mid){
        return qry(mid+1, r, x, y, 2*n+1);
    }
    return min(qry(l, mid, x, mid, 2*n), qry(mid+1, r, mid+1, y, 2*n+1));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q; build(1, N, 1);
    for (int i = 0, x, y, z;i<Q;i++) {
        cin >> x >> y >> z;
        upd(1, N, x, y, z, 1);
        cout << qry(1, N, x, y, 1) << " " << st[1] << "\n";
    }

}