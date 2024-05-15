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

const int MM = 1e5 + 2;
int n, m, burg[MM], dp[MM], suff[MM], last[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0;i<n;i++) {
        cin >> burg[i];
        //implement last and suff
    }

    for (int i = n;i>0;i--) {
        if (burg[0] == burg[i]) {
            dp[i] = 1;
        } else if (i != last[burg[i]]) {
            dp[i] = dp[last[burg[i]]];
        } else {
            dp[i] = 1/(n-i+1) * (1+suff[i]);
        }
    }

    cout << 1/n * suff[0];

}

