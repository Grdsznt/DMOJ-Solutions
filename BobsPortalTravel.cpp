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


int N;ll K;
int dist[20001], nxt[10001];

int main() {
    cin >> N >> K;
    for (int i = 1;i<=N;i++) {
        cin >> nxt[i];
    }
    memset(dist, -1, sizeof(dist));
    int cur = 1; dist[cur] = 0;
    // don't even need adj list
    while (true) {
        int next = nxt[cur];
        if (dist[next] != -1) {
            int cycle = dist[cur] - dist[next] +1;
            K %= cycle;
        }
        if (K == 0) {cout << cur << endl; return 0;}
        K--; dist[next] = dist[cur] + 1; cur = next;
    }
}


//int cycleLen;  vector<int> stck; vector<int> vec;
//unordered_map<int, int> mp;
//
//vector<int> adj[1001];
//
////void dfs(int u, int v) {
////    visited[u] = 1;
////    for (int vert: adj[u]) {
////        if (totalLen == K) return;
////        if (visited[vert] == 1) {
////            int cur = v;
////            vec.push_back(cur);
////            while (cur != u) {
////                cur = par[cur];
////                vec.push_back(cur);
////            }
////            cycleLen = dist[u] - dist[vert] + 1;
////            return;
////        } else if (visited[v] == 0) {
////            dist[v] = dist[u] + 1; totalLen++;
////            dfs(vert, u);
////        }
////        par[u] = v;
////    }
////    visited[u] = 2;
////}
//void dfs(int cur) {
//    visited[cur] = 1;  // Visited in stack
//    stck.push_back(cur);  // Push the current node to the stack
//
//    for (int nxt : adj[cur]) {
//        if (visited[nxt] == 1) {
//            // Get a cycle
//            cycleLen = dist[cur] - dist[nxt] + 1;
//
//            // Store nodes in the cycle by backtracking through the stack
//            while (!stck.empty()) {
//                int node = stck.back();
//                stck.pop_back();
//                vec.push_back(node);
//                if (node == nxt) {
//                    break;
//                }
//            }
//        } else if (visited[nxt] == 0) {
//            dist[nxt] = dist[cur] + 1;
//            dfs(nxt);
//        }
//    }
//
//    visited[cur] = 2;  // Visited but not in the stack anymore
//    stck.pop_back();  // Pop the current node from the stack
//}
//
//// how to track the nodes within a cycle
//
//
//int main () {
//    cin >> N >> K;
//    for (int i = 1, x;i<=N;i++) {
//        cin >> x;
//        adj[i].push_back(x);
//        mp[x] = i;
//    }
//
//    dfs(1);
//
//
//    cout << mp[vec[K % cycleLen]] << endl;
//
//}


//int N; ll K;
//unordered_map<int, int> mp;
//
//int main() {
//
//    cin >> N >> K;
//
//    for (int i = 1; i <= N; i++) {
//        cin >> mp[i];
//    }
//
//    int cur = 1;
//    // floyd tortoise and hare
//    int tortoise = cur, hare = cur, cycLen = 0;
//    ll rem;
//
//    do {
//        tortoise = mp[tortoise];
//        hare = mp[mp[hare]];
//    } while (tortoise != hare);
//
//    // Find the length of the cycle
//
//    do {
//        hare = mp[hare];
//        cycLen++;
//    } while (tortoise != hare);
//
//    if (K <= cycLen) {
//        rem = K;
//    } else {
//        int step = 0; tortoise = cur;
//
//        while (tortoise != hare) {
//            tortoise = mp[tortoise]; hare = mp[hare];
//            step++;
//        }
//
//        rem = (K - step) % cycLen;
//        cur = 1;
//
//        while (step > 0) {cur = mp[cur]; step--;}
//        while (rem > 0) {cur = mp[cur]; rem--;}
//    }
//    cout << cur << endl;
//}
