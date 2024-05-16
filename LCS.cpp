#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"


const int MM = 3e3+2;
string s, t, ans;
int n, dp[MM][MM], g[MM][MM];

int main(){
//    ios::sync_with_stdio(0); cin.tie(0);
//    cin >> s >> t;
//    for (int i = 1;i<=s.size();i++) {
//        for (int j = 1;j<=t.size();j++) {
//            if (s[i-1] != t[j-1]) {
//                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//            }else {
//                dp[i][j] = dp[i-1][j-1] + 1;
//            }
//        }
//    }
//    int r = s.size(), c = t.size();
//    while (r != 0 && c != 0) {
//        if (dp[r][c] == dp[r-1][c]) r--;
//        else if (dp[r][c] == dp[r][c-1]) c--;
//        else {
//            r--; c--; // go diagonally back
//            ans.push_back(s[r]); // can push back a string
//        }
//    }
//    reverse(ans.begin(), ans.end());
//    cout << ans << "\n";
    g[3][1] = 1; g[1][4] = 1;
    for (int i = )

}


