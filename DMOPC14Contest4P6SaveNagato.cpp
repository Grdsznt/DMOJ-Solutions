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

/* INPUTS */
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

/* TYPEDEF */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 5e5+3;
int n, dist1[MM], dist2[MM], mx = 0, furthest;
vector<int> adj[MM];

void dfs(int cur, int pre, int d, int dist[]) {
    if (d > mx) {
        mx = d; furthest = cur;
    }
    dist[cur] = d;
    for (int v:adj[cur]) {
        if (v != pre) dfs(v, cur, d+1, dist);
    }
}

int main() {
    cin >> n;
    for (int i= 1, u, v;i<n;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, 0, dist1);
    mx = 0;
    dfs(furthest, -1, 0, dist1);
    mx = 0;
    dfs(furthest, -1, 0, dist2);

    for (int i = 1;i<=n;i++){
        cout << max(dist1[i], dist2[i]) + 1<< "\n";
    }

}
