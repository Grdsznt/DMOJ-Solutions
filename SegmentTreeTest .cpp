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
    int l, r;
    int Min; int cnt;
};

node seg[4*MM], seg2[4*MM];
//pair<node, node> seg2[MM];

void build1(int l, int r, int val) { // build from the root
    seg[val].l = l;
    seg[val].r = r;
    if (l == r) {
        seg[val].Min = a[l];  return;
    }
    int mid = (l+r)/2;
    build1(l, mid, 2*val);
    build1(mid + 1, r, 2*val+1);
    seg[val].Min = min(seg[2*val].Min, seg[2*val+1].Min);

}
void build2(int l, int r, int val) { // build from the root
    seg2[val].l = l;
    seg2[val].r = r;
    if (l == r) {
        seg2[val].Min = a[l]; seg[val].cnt = 1; return;
    }
    int mid = (l+r)/2;
    build2(l, mid, 2*val);
    build2(mid + 1, r, 2*val+1);
    seg2[val].Min = gcd(seg2[2*val].Min, seg2[2*val+1].Min);
}

void upd1(int pos, int val, int num) {
    if (seg[num].l == pos && seg[num].r == pos) {
        seg[num].Min = val; return;
    }
    int mid = (seg[num].l + seg[num].r)/2;
    if (pos <= mid) upd1(pos, val, 2*num);
    else upd1(pos, val, 2*num+1);
    seg[num].Min = min(seg[2*num].Min, seg[2*num+1].Min);
} // out of bounds

void upd2(int pos, int val, int num) {
    if (seg2[num].l == pos && seg2[num].r == pos) {
        seg2[num].Min = val; return;
    }
    int mid = (seg2[num].l + seg2[num].r)/2;
    if (pos <= mid) upd2(pos, val, 2*num);
    else upd2(pos, val, 2*num+1);
    seg2[num].Min = gcd(seg2[2*num].Min, seg2[2*num+1].Min);
}

int qry1(int l, int r, int num){
    if(seg [num].l==l && seg[num].r == r)
        return seg[num].Min;
    int mid = (seg[num].l+seg[num].r)/2;
    if (r <= mid)
        return qry1(l, r, 2 * num);
    else if (l > mid)
        return qry1(l, r, 2 * num + 1);
    else return min(qry1(l, mid, 2*num), qry1(mid+1, r, 2*num+1));
}
int qry2(int l, int r, int num){
    if(seg2[num].l==l && seg2[num].r == r)
        return seg2[num].Min;
    int mid = (seg2[num].l+seg2[num].r)/2;
    if (r <= mid)
        return qry2(l, r, 2 * num);
    else if (l > mid)
        return qry2(l, r, 2 * num + 1);
    else return gcd(qry2(l, mid, 2*num), qry2(mid+1, r, 2*num+1));
}

int qry3(int l, int r, int val, int num){
    if(seg2[num].l==l && seg2[num].r == r)
        return seg2[num].Min == val ? seg[num].cnt : 0;
    int mid = (seg2[num].l+seg2[num].r)/2;
    if (r <= mid)
        return qry3(l, r, val,2 * num);
    else if (l > mid)
        return qry3(l, r, val, 2 * num + 1);
    return qry3(l, mid, val, 2*num) + qry3(mid+1, r, val, 2*num+1);
}
//pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
//    if (a.first > b.first)
//        return a;
//    if (b.first > a.first)
//        return b;
//    return make_pair(a.first, a.second + b.second);
//}

//int qryCnt(int l, int r, int num, int g) {
//    if (r < seg2[num].l || l < seg2[num].r) return 0;
//    if (l <= seg2[num].l && seg2[num].r <= r) return (seg2[num].Min == g) ? (seg2[num].r - seg2[num].l  + 1) : 0;
//    int mid = (seg2[num].l + seg2[num].r) / 2;
//    return qryCnt(l, r, 2*num, g);
//}

int qryCnt(int l, int r, int num, int g) {
    if (seg2[num].l == l && seg2[num].r == r)
        return (seg2[num].Min == g) ? (r - l + 1) : 0;
    int mid = (seg2[num].l + seg2[num].r) / 2;
    if (r <= mid)
        return qryCnt(l, r, 2 * num, g);
    else if (l > mid)
        return qryCnt(l, r, 2 * num + 1, g);
    else
        return qryCnt(l, mid, 2 * num, g) + qryCnt(mid + 1, r, 2 * num + 1, g);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0;i<N;i++) {
        cin >> a[i];
    }
    build1(0, N-1, 1);
    build2(0, N-1, 1);

    for (int i = 0;i<M;i++) {
        char c; cin >> c;
        if (c == 'C') {
            int x, v; cin >> x >> v;
            upd1(x, v, 1); upd2(x, v ,1);
        }else if (c == 'M') {
            int l, r; cin >> l >> r;
            cout << qry1(l, r, 1) << endl;
        }else if (c == 'G') {
            int l, r; cin >> l >> r;
            cout << qry2(l, r, 1) << endl;
        }else {
            int l, r, G; cin >> l >> r;
            G = qry2(l, r, 1);
            cout << qry3(l, r, G, 1);
        }
    }

}


