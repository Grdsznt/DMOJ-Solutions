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


int n, q;

const int MM = 2e5+3, LOG = log2(MM);

ll st[LOG+1][MM];

int qry (int l, int r) {
    int k = log2(r-l+1);
    return min(st[k][l], st[k][r-(1<<k)+1]);
}

int main() {

    cin >> n >> q;
    for (int i = 0;i<n;i++) {
        cin >> st[0][i];
    }
    for (int k = 1;k<=LOG;k++) {
        for (int i = 1; i+(1<<k)-1<=n;i++) {
            st[k][i] = min(st[k-1][i], st[k-1][i+(1<<k-1)]);
        }
    }

    for (int i = 1,v, l, r;i <= q;i++) {
        cin >> v >> l >> r;

        while (v && l <= r) {
            int lft = l, rit = r; int pos = r+1;
            while (lft <= rit) {
                int mid = (lft+rit)/2;
                if (qry(l, mid) <= v) {rit = mid-1; pos = mid;}
                else lft = mid + 1;
            }
            if (pos <= r) {
                v %= st[0][pos]; lft = pos + 1;
            }
            else break;
        }

        cout << v << "\n";
    }


}
