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


int N, K;

ll dist[100002];

int cnt[100002][2];

vector<pii> adj[100002];

void dfs(int u, int v) {
    cnt[u][dist[u]%2]++;
    for (auto [f, s]: adj[u]) {
        if (f != v) {
            dist[f] = dist[u] + s;
            dfs(f, u);
            cnt[u][0] += cnt[f][0];
            cnt[u][1] += cnt[f][1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0, a, b, w;i<N-1;i++) {
        cin >> a >> b;
        adj[a].push_back({b, w}); adj[b].push_back({a, w});

    }
    dfs(1, 0);
    ll ttE = (ll)N*(N-1)/2, odd = (ll) cnt[1][0] * cnt[1][1], even = ttE-odd, ans = abs(odd-even);
    for (int i = 1;i<=N;i++) {
        ll nOdd = cnt[1][1] - cnt[i][1] + cnt[i][0], nEven = cnt[1][0] - cnt[i][0] + cnt[i][1];
        ans = min(ans, abs(ttE-2*(nOdd*nEven)));
    }
    cout << ans << endl;

}
