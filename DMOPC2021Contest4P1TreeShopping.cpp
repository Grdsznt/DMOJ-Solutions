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

struct triangle {
    pii f, s, t;
};



const int MM = 5e5 + 3;

int q, n;
vector<pii> pts;
vector<triangle> triangles;

bool tri(triangle x, pii p) {
//    if ((p.first >= x.f.first && p.first <= x.s.first) || (p.first >= x.s.first && p.first <= x.t.first) || (p.first >= x.t.first && p.first <= x.f.first)) {
//        if ((p.second >= x.f.second && p.second <= x.s.second) || (p.second >= x.s.second && p.second <= x.t.second) || (p.second >= x.t.second && p.second <= x.f.second)) {
//
//        }
//    }

//    if (x.f.first == x.s.first && x.f.second == x.t.second) {
//        if (x.t.first > x.f.first) {
//            // x must large
//            pii frac = {x.s.second-x.t.second, x.s.first-x.t.first};
//            pii b = {-(x.s.second*frac.first) , frac.second};
//            if (frac.first * frac.second > 0) {
//
//            }
//        } else {
//            // x must small
//        }
//    } else if (x.f.first == x.t.first && x.s.second == x.f.second){
//
//    }
//    else if (x.s.first == x.t.first && x.s.second == x.f.second || x.s.first == x.f.first && x.s.second == x.t.second) {
//
//    } else {
//
//    }


    int s = (x.f.first - x.t.first) * (p.second - x.t.second) - (x.f.second - x.t.second) * (p.first - x.t.first);
    int t = (x.s.first - x.f.first) * (p.second - x.f.second) - (x.s.second - x.f.second) * (p.first - x.f.first);

    if ((s < 0) != (t < 0) && s != 0 && t != 0) return false;
    int d = (x.s.first - x.s.first) * (p.second - x.s.second) - (x.t.second - x.s.second) * (p.first - x.s.first);
    return d == 0 || (d < 0) == (s + t <= 0);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0,a,b,c,d,e,f;i<n;i++) {
        cin >> a >> b >> c >> d >> e >> f;
        triangles.push_back({{a,b}, {c,d}, {e, f}});
    }
    for (int i = 0,a,b;i<q;i++) {
        cin >> a >> b;
        pts.push_back({a,b});
    }

    for (int i = 0;i<q;i++) {
        int ans = 0;
        for (int j = 0;j<n;j++) {
            if (tri(triangles[j], pts[q])) ans++;
        }
        cout << ans << endl;
    }


}