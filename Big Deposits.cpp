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

const int MM = 2e5+3;
int P, Y;
ll T, ans = 0;

bool check(ll n) {
    ll sum = 0;
    for (ll i = 0;i<Y;i++) {
        sum += n; sum += sum*P/100;
        if (sum >= T) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> P >> Y >> T;
    ll lo = 1, hi = T;
    while (lo <= hi) {
        ll mid = (lo+hi)/2;
        if (check(mid)) {
            ans = mid; hi = mid-1;
        }
        else lo = mid+1; //minimize
    }

    cout << ((ans == 0) ? lo : ans) << endl;
}
