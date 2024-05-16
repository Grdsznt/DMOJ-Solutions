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

const int MM = 5e5 +2;
int N, M, in[MM], p[MM], ans[MM];

vector<int> adj[103];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1;i<=N;i++) {
        cin >> p[i];
    }
    for (int i = 1, a, b;i<=M;i++) {
        cin >> a >> b;
        adj[b].push_back(a); adj[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i<=)

    for (int i = 0; i < N; ++i) {
        pii mi = {INT_MAX,INT_MAX}; int u = -1;
        for (int j = 1; j <= N; ++j) {
            if (!vis[j] && dist[j] < mi) {
                mi = dist[j]; u = j;
            }
        }
        vis[u] = true;
        for (auto [f, s, t]: adj[u]) {
            if (dist[f] > mi) {
                dist[f] = mi;
            }
        }
    }

}