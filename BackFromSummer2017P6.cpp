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

struct E { int l, w, h, p, id;} e[100002];
int N, pre[100002]; ll dp[100002], bit[5002][5002], sol; unordered_map<ll, int> mp;
bool cmp(E x, E y){ return x.h < y.h || (x.h == y.h && x.l < y.l) || (x.h==y.h && x.l==y.l && x.w < y.w);}
ll qry(int r, int c){
    ll ans = -1;
    for(int i=r; i>0; i-=i & -i)
        for(int j=c; j>0; j-=j&-j)
            ans = max(ans, bit[i][j]);
    return ans;
}
void upd(int r, int c, ll val){
    for(int i=r; i<=5000; i+= i&-i)
        for(int j=c; j<=5000; j+=j & -j)
            bit[i][j] = max(bit[i][j], val);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> e[i].l >> e[i].w >> e[i].h >> e[i].p;
        if(e[i].l > e[i].w) swap(e[i].l, e[i].w); e[i].id = i;
    }
    sort(e+1, e+N+1, cmp);
    mp[0] = 0;
    for(int i=1; i<=N; i++){
        dp[i] = qry(e[i].l, e[i].w);
        pre[i] = mp[dp[i]]; dp[i] += e[i].p;
        mp[dp[i]] = i; sol = max(sol, dp[i]);
        upd(e[i].l, e[i].w, dp[i]);
    }
    printf("%lld\n", sol);
        
    vector<int> tmp;
    for(int i = mp[sol]; i>0; i=mp[sol]){
        tmp.push_back(i); sol = dp[pre[i]];
    }
    cout << tmp.size() << "\n";
    for(int i=0; i<tmp.size(); i++) {
        cout << e[tmp[i]].id << "\n";
    }

}