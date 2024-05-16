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


const int MM = 1e5+3;

int N, M, a[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0;i<N;i++) cin >> a[i];

    ll l = (ll) max_element(a, a+N), r = 0;

    for (int i = 0;i<N;i++) {
        r += a[i]
    }

}
