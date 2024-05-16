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


const int MM = 1e5+4;

int N, ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
//    if (N == 2) {cout << 1 << endl; return 0;}

    int numObs = N / 2;

    if (numObs % 2 == 1 && N % 2 == 0) {
        numObs--;
    }
    ll ans = 2*N-numObs-1;

    if (N % 4 == 2) {
        ans -= 2;
    } else if (N % 4 == 1) {
        ans--;
    }
    cout << ans << endl;

}
