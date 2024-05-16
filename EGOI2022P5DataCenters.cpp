#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

//const int MM = 1e5+3;
//int n, s;
//vector<int> a(MM), b(MM);
//
////greater<int>()
//int main(){
//    ios::sync_with_stdio(0); cin.tie(0);
//    cin >> n >> s;
//    for (int i = 0;i<n;i++) {
//        cin >> a[i];
//        a[i] = -a[i]; // want to sort descending order so use negative instead of comparator
//    }
//    sort(a.begin(), a.end());
//    for (int k = 1, m, c; k<=s;k++) {
//        cin >> m >> c;
//        for (int i = 0;i<c;i++) a[i] += m; // for first c centers, subtract m from magnitude
//        merge(a.begin(), a.begin()+c, a.begin()+c, a.end(), b.begin()); // O(n) merge 2 sorted subarrays into 1 (basically 2 pointer)
//        // use vector b as a placeholder (since in mergesort you need another array to set the value anyways)
//        swap(a, b); // swap the address of a and b O(1)
//    }
//    for (int i = 0;i<n;i++) cout << -a[i] << " \n" [i == n-1];
//}

const int MM = 1500+3;
int n, dp[MM][MM], v[MM], v2[MM];
string str[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) dp[i][j] = 1;
    }
    for (int i = 0, val;i<n;i++) {
        string s;
        cin >> s >> val;
        str[i] = s;
        v[i] = val;
    }
    for (int i = 0;i<n;i++) {
        cin >> v2[i];
    }
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            if (str[i][j] == 'R') dp[i][j+1] += dp[i][j];
            else dp[i+1][j] += dp[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0;i<n;i++) {
        ans += dp[i][n] * v[i] + dp[n][i] * v[i];
    }
}

