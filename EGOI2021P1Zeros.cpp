#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e5+3;
int a, b;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b; a--;
    ll m2 = LLONG_MIN, m5 = LLONG_MIN;
    ll exp = 1;
    for (ll i = 2;i<=6e18;i *= i) {
        if (b/i - a/i <= 0) {
            m2 = exp - 1; break;
        }
        exp++;
    }
    exp = 1;
    for (ll i = 5;i<=6e18;i *= i) {
        if (b/i - a/i <= 0) {
            m5 = exp - 1; break;
        }
        exp++;
    }

    cout << min(m2, m5) << "\n";
}
