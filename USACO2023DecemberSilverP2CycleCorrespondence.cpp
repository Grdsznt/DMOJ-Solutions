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

int n, k, a[MM], b[MM], posa[MM], posb[MM], cnt[MM], ans = INT_MIN;
si out;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1;i<=k;i++) {
        cin >> a[i]; out.insert(a[i]);
        posa[a[i]] = i;
    }
    for (int i = 1;i<=k;i++) {
        cin >> b[i]; out.insert(b[i]);
        posb[b[i]] = i;
    }

    for (int i = 1;i<=k;i++) {
        if (posb[i] == 0 || posa[i] == 0) continue;
        int diff = posb[i] - posa[i];
        if (diff < 0) diff += n;
        cnt[diff]++;
    }
    for (int i = 0;i<n;i++) {
        ans = max(ans, cnt[i]);
    }
    ans += n - out.size();

    cout << ans << endl;
}