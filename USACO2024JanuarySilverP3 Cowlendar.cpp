#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 3e5+3;
ll N, a[MM], lmt, ans;

set<ll> u;

bool check(ll x) {
    unordered_set<ll> rem;
    for (int i = 0;i<N;i++) {
        rem.insert(a[i] % x);
    }
    return rem.size() <= 3;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0;i<N;i++) {
        cin >> a[i]; lmt = min(a[i], lmt);
    }
    lmt/=4;
    sort(a, a+N); N = unique(a, a+N) - a;
    if (N <= 3) {
        cout << (1+lmt)*lmt/2 << "\n"; return 0;
    }
    for (int i = 0;i<4;i++) {
        for (int j = i+1;j<4;j++) {
            ll dif = a[j] - a[i];
            for (ll k = 1; k*k <= dif && k <= lmt; k++) {
                if (dif%k) continue;
                if (!u.count(k) && check(k)) u.insert(k);
                if (dif/k <= lmt && !u.count(dif/k) && check(dif/k)) u.insert(dif/k);
            }
        }
    }

    for (ll i : u) ans += i;
    cout << ans << "\n";
}
