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



int N, ans = 0;
vector<pll> vec;

bool same(pll a, pll b) {
    return a.first*b.second == a.second*b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0, t, p;i<N;i++) {
        cin >> t >> p;
        vec.push_back({t, p});
    }
//    sort(vec.begin(), vec.end());
//    for (int i = 0;i<N;i++) {
//        for (int j = i+1;j<N;j++) {
//            auto [f, s] = vec[i]; auto [f1, s1] = vec[j];
//            if (f == f1) continue;
//            double slope = (double) (s1-s)/(f1-f); double b = f - slope*s;
//            bool above = false, below = false, trend = true;
//            for (int k = i+1;k<j;k++) {
//                double res = slope*vec[k].first + b;
//                if (vec[k].second > res) above = true;
//                else if (vec[k].second < res) below = true;
//                if (above && below) {
//                    trend = false; break;
//                }
//            }
//            if (trend) ans++;
//        }
//    }

    for (int i = 0;i<N;i++) {
        pll maxS = {-2e9, 1}, minS{2e9, 1};
        for (int j = i+1;j<N;j++) {
            auto [f, s] = vec[i]; auto [f1, s1] = vec[j];
            if (maxS.first * (f1-f) < (s1-s) * maxS.second) maxS = {s1-s, f1-f};
            if (minS.first * (f1-f) > (s1-s) * minS.second) minS = {s1-s, f1-f};
            if (same(maxS, {s1-s, f1-f}) || same(minS, {s1-s, f1-f})) ans++;
        }
    }

    cout << ans << "\n";

}
