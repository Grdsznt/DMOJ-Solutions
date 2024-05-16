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

const int MM = 13 << 2;
int N, Q;
int bit[MM][MM], h[MM];


int qry (int r, int c) {
    int ans = 0;
    for (int i = r+1; i; i-=i&-i) {
        for (int j = c+1; j; j-=j&-j) {
            ans += bit[i][j];
        }

    }
    return ans;
}

void update(int r, int c, int val) {
    for (int i = r+1; i<MM;i += i&-i) {
        for (int j = c+1; j<MM; j += j& -j) {
            bit[i][j] += val;
        }
    }
}


int main() {


    cin >> N;
    vector<vector<int>> gph(N+1);


    for (int i = 0;i<N;i++) {

        cin >> h[i]; update(i, h[i], 1);

    }
    cin >> Q; int o, l, r, a, b;
    for (int i = 0;i<Q;i++) {
        cin >> o;
        if (o == 1) {
            cin >> a >> b;
            cout << qry(r, b) - qry(l-1, b) - qry(r, a-1) + qry(l-1, a-1);
        } else {
            update(l, h[l], -1); h[l] = r; update(l, h[l], 1);
        }



    }



    cout << ans << endl;
}
