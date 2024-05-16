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

struct node {
    int u, v; ll h;
};

const int MM = 2e5+3, l = 1 << 18;
int n, h[MM], num[MM], rev[MM];
ll st[2*l];
vi v;
mii indx;

void upd(int x, int val) {
    for (int i = x;i > 0;i /= 2) {
        st[i] += val;
    }
}

int qry(int x, ll val) {
    if (x >= l) return x - l;
    if (st[2*x] >= val) return qry(2*x, val);
    return qry(2*x+1, val - st[2*x]);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> h[i] >> num[i]; v.push_back(h[i]);
    }
    sort(v.begin(), v.end());

    // del dup elements
    v.erase(unique(v.begin(), v.end()), v.end());
    int k = 0;
    for (int i = 0;i<v.size();i++) {
        indx[v[i]] = k; rev[k] = v[i]; k++;
    }
    ll ind = 0;
    for (int i = 0;i<n;i++) {
        ind += num[i];
        upd(indx[h[i]] + l, num[i]);
        cout << rev[qry(1, (ind+1)/2)] << endl;
    }


}

