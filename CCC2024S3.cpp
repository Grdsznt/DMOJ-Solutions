#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 3e5+3;
int N, a[MM], b[MM], first[MM];
set<int> u;
vector<pii> rit, lft, seg;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0;i<N;i++) {
        cin >> a[i];
    }
    for (int i = 0;i<N;i++) {
        cin >> b[i];
    }
    int l = 0, val = b[0];
    for (int i = 0;i<N;i++) {
        if (b[i] != val) {
            seg.push_back({l, i-1});
            l = i;
            val = b[i];
        }
        if (i == N-1) {
            if (b[i] == val) seg.push_back({l, i});
        }
    }
    int k = 0;
    for (auto [f, s] : seg) {

        int fst; bool bo = false;
        while (k < N) {
            if (a[k] == b[f]) {
                fst = k; bo = true; break;
            }
            k++;
        }
        if (!bo) {
            cout << "NO\n"; return 0;
        }
        if (f < fst) {
            lft.push_back({f, fst});
        }
        if (s > fst) {
            rit.push_back({fst, s});
        }
    }
    cout << "YES\n";
    cout << lft.size() + rit.size() << "\n";
    for (auto [f, s] : lft) {
        cout << "L " << f << " " << s << "\n";
    }
    for (int i = rit.size()-1;i>=0;i--) {
        cout << "R " << rit[i].first << " " << rit[i].second << "\n";
    }


    // if first[value at seg] > R impossible
//    for (int i = 0;i<N;i++) {
//
//        cin >> b[i]; u.insert(b[i]);
//    }
//
//    if (u.size() == 1) {
//        if (a[1] == b[0] && a[0] == b[0]) {
//            cout << "YES\n0\n"; return 0;
//        }
//        if (a[0] == b[0]) {
//            cout << "YES\n1\n";
//            cout << "R 0 1\n";
//            return 0;
//        }
//        if (a[1] == b[0]) {
//            cout << "YES\n1\n";
//            cout << "L 0 1\n";
//            return 0;
//        }
//        cout << "NO";
//    } else {
//        if (a[0] == b[0] && a[1] == b[1]) {
//            cout << "YES\n";
//            cout << "0\n";
//        }else {
//            cout << "NO\n";
//        }
//    }



}
