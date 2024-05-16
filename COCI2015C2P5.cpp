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

const int MM = 1e6+4;
int N, P, a[MM], bit[MM], idx; ll psa[MM], ans = 0;
vector<ll> comp;


void upd(int pos, int val) {
    for (int i = pos; i<MM;i += i&-i) {
        bit[i] += val;
    }
}

int qry(int pos) {
    int ret = 0;
    for (int i = pos; i; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}


int main() {
    cin.tie(0);

    cin >> N;
    for (int i = 1;i<=N;i++) cin >> a[i];
    cin >> P;
    for (int i = 1;i<=N;i++) {
        a[i] -= P; psa[i] = psa[i-1] + a[i];
        comp.push_back(psa[i]);
    }

    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    int p0 = lower_bound(comp.begin(), comp.end(), 0) - comp.begin() + 1;
    upd(p0, 1);

    for (int i = 1;i<=N;i++) {
        ll rk = lower_bound(comp.begin(), comp.end(), psa[i]) - comp.begin() + 1;
        ans += qry(rk);
        upd(rk, 1);
    }


    cout << ans << "\n";
}
