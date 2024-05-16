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
int K, P, X;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> P >> X;
    double ans = DBL_MAX;
    for (int i = 1; i<=10000;i++) {
        double res = i*X + (double)(K*P)/i;
        ans = min(ans, res);
    }
    cout << fixed << setprecision(3) << ans << endl;
}
