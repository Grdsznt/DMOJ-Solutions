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

const int MM = 2e5 + 3;

int T, h[MM], a[MM], t[MM], lo = INT_MIN, up = INT_MAX;
bool imp = false;
vector<pii> compare;



void days(int hi, int hj, int ai, int aj) {
    if (ai > aj) {
        int ret = round((double)(hj - hi)/(ai-aj));
        if (ret < 0) imp = true;
        else lo = max(lo, ret);
    } else if (aj > ai) {
        int ret = round(round((double)(hi - hj)/(aj-ai)));
        if (ret < 0) imp = true;
        else up = min(up, ret);
    } else {
        if (hi > hj) {
            lo = max(lo, 0);
        } else {
            imp = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i = 0, n;i<T;i++) {
        cin >> n;
        for (int j = 0;j<n;j++) cin >> h[j];
        for (int j = 0;j<n;j++) cin >> a[j];
        for (int j = 0;j<n;j++) cin >> t[j];
        int indx = 0;
        while (compare.size() < n) {
            for (int j = 0;j<n;j++) {
                if (t[j] == indx) {
                    compare.push_back({h[j], a[j]});
                    indx++;
                }
            }
        }
        for (int j = 0;j<compare.size()-1;j++) {
            auto [f1, s1] = compare[j];
            auto [f2, s2] = compare[j+1];
            days(f1,f2, s1, s2);
        }

        if (lo != up && !imp) {
            cout << lo << endl;
        } else {
            cout << -1 << endl;
        }
        lo = INT_MIN; up = INT_MAX;
        imp = false;
        memset(h, 0, sizeof(h)); memset(a, 0, sizeof(a)); memset(t, 0, sizeof(t));
    }
}
