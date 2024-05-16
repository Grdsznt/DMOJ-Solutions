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

int N, Q;



vector<pii> g[6002];
vector<int> eulerT;
int dep[6002], indx[6002];

ll dist[6002];

pii st[12004][15];

void dfs(int u, int v) {
    indx[u] = eulerT.size(); eulerT.push_back(u);
    for (auto [b, w] : g[u]) {
        if (b!=v) {
            dep[b] = dep[u] + 1; dist[b] = dist[u] + w;
            dfs(b, u);
            eulerT.push_back(u);
        }
    }
}

int lca(int u, int v) {
    int l = min(indx[u], indx[v]), r = max(indx[u], indx[v]);
    int k = log2(r-l+1);
    return min(st[l][k], st[r-(1<<k)+1][k]).second;
}

int main() {
    cin >> N;
    for (int i = 1, a, b, w;i<N;i++) {
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs(0, -1); // use prev of -1 to start

    // build sparse table

    for (int i = 0;i<eulerT.size();i++) {
        st[i][0] = {dep[eulerT[i]], eulerT[i]};
    }
    int LOG = log2(eulerT.size());
    for (int k = 1;k<=LOG;k++) {
        for (int i = 0;i + (1<<k-1) < eulerT.size(); i++) {
            st[i][k] = min(st[i][k-1], st[i + (1<<k-1)][k-1]);
        }
    }
    cin >> Q;
    for (int i = 0, u, v;i<Q;i++) {
        cin >> u >> v;
        cout << dist[u] + dist[v] - 2*dist[lca(u,v)] << endl;
    }

}

//int main() {
//    cin >> N;
//    for (int i = 0, a, b, w;i<N-1;i++) {
//        cin >> a >> b >> w;
//        g[a].push_back({b, w});
//        g[b].push_back({a, w});
//    }
//
//
//    cin >> Q; priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> q;
//    for (int i = 0, u, v;i<Q;i++) {
//        ll dist[N];
//        cin >> u >> v;
//        for (int j = 0;j<N;j++) {
//            dist[j] = LONG_LONG_MAX;
//        }
//        dist[u] = 0;
//        q.push({u, 0});
//        while (!q.empty()) {
//            int nxt = q.top().first;
//            ll minVal = q.top().second;
//            q.pop();
////
////            if (minVal > dist[nxt]) {
////                continue;
////            }
//            for (pair<int, int> p : g[nxt]) {
//                if (dist[p.first] > dist[nxt] + p.second) {
//                    dist[p.first] = dist[nxt] + p.second;
//                    q.push({dist[p.first], p.first});
//                }
//            }
//        }
//
//        cout << dist[v] << endl;
//
//
//    }
//}