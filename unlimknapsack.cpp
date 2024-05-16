#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"





const int MM = 1e6+3;
int n, m, dp[MM], item[MM], c[MM];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i<n;i++) {
        cin >> item[i] >> c[i];
    }
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            dp[j] = min(dp[j], c[i] + dp[j-item[i]]);
        }
    }
}


