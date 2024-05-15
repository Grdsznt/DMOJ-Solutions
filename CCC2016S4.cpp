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


// /* INPUTS */
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

// /* UTILS */
// #define MOD 1000000007
// #define PI 3.1415926535897932384626433832795
// ll min(ll a,int b) { if (a<b) return a; return b; }
// ll min(int a,ll b) { if (a<b) return a; return b; }
// ll max(ll a,int b) { if (a>b) return a; return b; }
// ll max(int a,ll b) { if (a>b) return a; return b; }
// ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
// ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
// bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }


// /* TYPEDEF */
// typedef long int int32;
// typedef unsigned long int uint32;
// typedef long long int int64;
// typedef unsigned long long int  uint64;
#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"


int N, dp[402][402], psa[402], ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> dp[i][i];
        ans = max(ans, dp[i][i]);
        if (i == 0) psa[0] = dp[i][i];
        else psa[i] = psa[i - 1] + dp[i][i];
    }
    for (int len = 1; len < N; len++) {
        for (int l = 0; l < N - len; l++) {
            int r = l + len;
            int j = l + 1;
            int k = r;
            while (j <= k) {
                if (dp[l][j - 1] && dp[l][j - 1] == dp[k][r] && (j == k || dp[j][k - 1])) {
                    dp[l][r] = max(dp[l][r], dp[l][j - 1] + dp[j][k - 1] + dp[k][r]);
                    ans = max(ans, dp[l][r]);
                    break;
                }
                if (psa[j - 1] - psa[l - 1] < psa[r] - psa[k - 1]) j++;
                else k--;
            }
        }
    }


    cout << ans;

}