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
struct Node {
    int tot, mxOn, mxOff, leftOn, leftOff, rightOn, rightOff;
    Node(int tot = 0, int length = 1) : tot(tot), mxOn(tot), mxOff(length * !tot),
                                        leftOn(tot), rightOn(tot),
                                        leftOff(length * !tot), rightOff(length * !tot) {}
};

int N, Q;
Node st[4*MM];

Node merge(const Node &left, const Node &right, int lSize, int rSize) {
    Node parent;

    parent.tot = left.tot + right.tot;

    // If the left seg on, include on from right
    // If the right seg on, include on from left
    parent.leftOn = (left.tot == lSize) ? lSize + right.leftOn : left.leftOn;
    parent.rightOn = (right.tot == rSize) ? right.rightOn + left.rightOn : right.rightOn;


    // If the left seg off, include off from right
    // If the right seg off, include off from left
    parent.leftOff = (left.tot == 0) ? lSize + right.leftOff : left.leftOff;
    parent.rightOff = (right.tot == 0) ? right.rightOff + left.rightOff : right.rightOff;

    // Maximum contiguous off and on segs
    parent.mxOn = max({left.mxOn, right.mxOn, left.rightOn + right.leftOn});
    parent.mxOff = max({left.mxOff, right.mxOff, left.rightOff + right.leftOff});

    return parent;
}



void upd(int l, int r, int pos, int n) {
    if (l == r) {st[n].tot ^= 1; st[n] = Node(st[n].tot, 1); return;}
    int m = (l+r)/2;
    if (pos<=m) upd(l, m, pos, 2*n);
    else upd(m+1, r, pos, 2*n+1);
    st[n] = merge(st[2*n], st[2*n+1], m-l + 1, r-m);
}

Node qry(int l, int r, int x, int y, int n) {
    if (x > r || y < l) return Node();
    if (x <= l && y >= r) return st[n];
    int m = (l + r) / 2;

    Node lans = qry(l, m, x, min(y, m), 2 * n);
    Node rans = qry(m + 1, r, max(x, m + 1), y, 2 * n + 1);

    if (x > m) return rans;
    if (y <= m) return lans;

//    return merge(lans, rans, min(y, m) - max(x, l) + 1, min(r, y) - max(x, m + 1) + 1);
    return merge(lans, rans, m - l + 1, r - m);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    for (int i = 0;i<Q;i++) {
        string s; cin >> s;
        if (s.compare("TOGGLE") == 0) {
            int x; cin >> x;
            upd(1, N, x, 1);
        } else if (s.compare("ON") == 0) {
            int l, r; cin >> l >> r;
            Node n = qry(1, N, l, r, 1);
            cout << n.mxOn << endl;
        } else {
            int l, r; cin >> l >> r;
            Node n =  qry(1, N, l, r, 1);
            cout << n.mxOff << endl;
        }
    }


}

