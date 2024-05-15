#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* TYPES  */
#define ll long long
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define vi vector<int>
// #define vll vector<long long>
// #define mii map<int, int>
// #define si set<int>
// #define sc set<char>


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
const int Max = 1e6+3;
int N, C, a[2*Max], cnt[Max]; ll ans;

ll nC2(int n) {
    if (n<2) return 0;
    return (ll) n*(n-1)/2;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    for (int i = 0;i<N;i++) {
        cin >> a[i]; 
        a[i+N] = a[i] + C;
        cnt[a[i]]++;
    }
    sort(a, a+2*N);
    ans = (ll)N*(N-1)*(N-2)/6; // max num triplets
    for (int i = 0, j = 0;i<N;i++) { // 2 pointer section
        while (j < 2*N && a[j]-a[i]<= C/2) j++;
        ans -= nC2(j-i-1);
         // subtract all 
    }
    if (C % 2 == 0) {
        for (int i = 0;i<C/2;i++) {
            ans += cnt[i] * nC2(cnt[i+C/2]) + cnt[i] * nC2(cnt[i+C/2]);
        }
    }
    cout << ans << endl;
}

