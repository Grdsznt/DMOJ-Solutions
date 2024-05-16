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

const int MM = 103;
int n, m, k, a[MM], dang = 0, cst = 0, dist[MM], rnk[MM], p[MM];
//vector<array<int, 3>> adj[MM];
bool vis[MM];

vector<array<int, 4>> edges;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void u(int x, int y) {
    x = find(x); y = find(y);
    if (rnk[x] > rnk[y]) p[y] = x;
    else p[x] = y;
    rnk[y] += rnk[x] == rnk[y];
}

int main() {
    cin >> n >> m;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

    for (int i = 1;i<=n;i++) {
        rnk[i] = 0; p[i] = i;
    }
    for (int i = 1, a, b, c, d;i<=m;i++) {
        cin >> a >> b >> c >> d;
//        adj[a].push_back({d, c, b});
//        if (i == 1) {
//            pq.push({0, 0, b});
//        }
//        adj[b].push_back({d, c, a});

        edges.push_back({d, c, a, b});
    }

    sort(edges.begin(), edges.end());

    for (auto [f, s, t, fo] : edges) {
        if (find(t) != find(fo)) {
            u(t, fo); dang += f; cst += s;
        }
    }
//    while(!pq.empty()) {
//         auto [f, s, t] = pq.top();
//         pq.pop();
//         if (vis[t]) continue;
//         vis[t] = true;
//         dang += f; cst += s;
//         for (auto [typ, w, v] : adj[t]) {
//             pq.push({typ, w, v});
//         }
//    }

    cout << dang << " " << cst << "\n";
}
