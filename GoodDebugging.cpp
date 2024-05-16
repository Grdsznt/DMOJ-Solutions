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
int N, M, L; ll st[4*MM], lz[4*MM];
//lazy propagation
void pd(int l, int r,int n) {
    int lc = 2*n, rc = 2*n+1, mid = (l+r)/2;
    st[2*n] = (mid-l + 1) - st[lc]; lz[lc] ^= 1; // left child
    st[2*n] = (r-mid) - st[rc]; lz[rc] ^= 1; // right child
    lz[n] = 0; // clear it
}
void build(int l, int r, int n) {
    if (l == r) {
        st[n] = 1; lz[n] = 0; return;
    }
    int mid = (l+r)/2;
    build(l, mid, 2*n); build(mid+1, r, 2*n+1);
    st[n] = min(st[2*n], st[2*n+1]);
}
void upd(int l, int r, int x, int y, int n) {
    if (l == x && r == y) { st[n] = (r-l+1) - st[n]; lz[n] ^= 1; return;}
    if (lz[n]) pd(l, r, n);
    int mid = (l+r)/2;
    if (y <= mid) {
        upd(l, mid, x, y,  2*n);
    } else if (x > mid){
        upd(mid+1, r, x, y, 2*n+1);
    } else {
        upd(l, mid, x, mid,  2*n); upd(mid+1, r, mid+1, y, 2*n+1);
    }
    st[n] = st[2*n] + st[2*n+1]; // pushup
}

int qry (int l, int r, int k, int n) {
    if (l == r) return l;
    if (lz[n])  pd(l, r, n);
    int mid = (l+r)/2;
    if (st[2*n] < k) { return qry(l, mid, k - st[2*n], 2*n+1);}
    else return qry(l, mid, k, 2*n);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> L ; build(1, N, 1);
    for (int i = 0, a, b;i<M;i++) {
        cin >> a >> b;
        upd(1, N, a, b, 1);
        if (st[1] < L) cout << "AC?\n";
        else cout << qry(1, N, L, 1)  << "\n";
    }

}


