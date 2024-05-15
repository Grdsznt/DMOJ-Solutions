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

int N, M, furthest = 0, diam = 0;
const int MM = 1e6+3;
int dist[MM], vis[MM];
bool pho[MM]; vector<int> adj[MM];
int trailLen = 0;


void dfs(int u, int pre) {
    for (int v: adj[u]) {
        if (v != pre) {dfs(v, u); if (pho[v]) pho[u] = true;}
        //tree pruning, check if subtree contain pho restaurant
    }
}
void dfs2(int u, int pre, int dist) {
    if (dist > diam) {diam = dist; furthest = u;}
    for (int v: adj[u]) {
        if (v != pre && pho[v]) {dfs2(v, u, dist+1);}
       
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M; int x;
    for (int i = 0;i<M;i++) {
        cin >> x;
        pho[x] = true;
    }
    for (int i = 0,a, b;i<N-1;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(x, -1);

    dfs2(x, -1, 0);
    dfs2(furthest, -1, 0);
    int edges = -1;
    for (int i = 0;i<N;i++) {
        if (pho[i]) edges++;
    }
    cout << 2*(edges) - diam << "\n";

}