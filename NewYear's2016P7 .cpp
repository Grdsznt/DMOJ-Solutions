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


int N, K, Q;
const int LOG = __lg(1010);

int a[1003];

int st1[1003][LOG], st2[1003][LOG];

int qryM (int l, int r) {
    int k = 31-__builtin_clz(r-l+1);
    return max(st2[l][k], st2[r-(1<<k)+1][k]);
}

int qrym (int l, int r) {
    int k = 31-__builtin_clz(r-l+1);
    return min(st1[l][k], st1[r-(1<<k)+1][k]);
}


int main() {
    cin >> N >> K;
    for (int i = 0;i<N;i++) {
        cin >> a[i];
    }

    for (int i = 0;i<N;i++) {
        st1[i][0] = a[i];
    }
    for (int k = 1;k<=LOG;k++) {
        for (int i = 0;i + (1<<k-1) < N; i++) {
            st1[i][k] = min(st1[i][k-1], st1[i + (1<<k-1)][k-1]);
        }
    }

    for (int i = 0;i<N;i++) {
        st2[i][0] = a[i];
    }
    for (int k = 1;k<=LOG;k++) {
        for (int i = 0;i + (1<<k-1) < N; i++) {
            st2[i][k] = max(st2[i][k-1], st2[i + (1<<k-1)][k-1]);
        }
    }
    cin >> Q; bool broke = false;
    for (int i = 0, l, r;i<Q;i++) {
        cin >> l >> r;

        for (int len = r-l;len>=1;len--) {
            for (int j = l-1;j<r-len;j++) {
                if((qryM(j, j+len)-qrym(j, j+len)) <= K) {
                    cout << j+1 << " " << j+len+1 << endl; broke = true;
                    break;
                }
            }
            if (broke) break;
        }
        broke = false;

    }


}
