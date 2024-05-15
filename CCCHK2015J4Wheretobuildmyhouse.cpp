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

const int MM = 5e5 + 3;

int l, n, ans = INT_MIN;
vector<pii> intervals;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> n;
    for (int i = 0,a,b;i<n;i++) {
        cin >> a >> b;
        intervals.push_back({a,b});
    }
    sort(intervals.begin(), intervals.end());
    for (int i = 0;i<n-1;i++) {
        int diff = intervals[i+1].first - intervals[i].second;
        if (diff > 0) {
            ans = max(ans, diff);
        }
    }
    ans = max(intervals[0].first, ans);
    ans = max(l - intervals[n-1].second, ans);

    cout << ans <<  endl;

}