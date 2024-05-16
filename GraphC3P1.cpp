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


int N, M, K;
const int MM = 3e4+5;
int ans = MM;
int dist[MM];
vector<int> src;

void bfs(vector<vector<int>> gph, vector<int> sources) {
    bool visited[N+1]; queue<int> q;
    for (int i: sources) {
        q.push(i); visited[i] = true; dist[i] = 0;
    }

    while (!q.empty()) {

        int v = q.front();
        q.pop();
        for (int i: gph[v]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[v] + 1;
            }
        }

    }


}

int main() {


    cin >> N >> M;
    vector<vector<int>> gph(N+1);
    for (int i = 0;i<M;i++) {
        int a, b;
        cin >> a >> b;

        gph[a].push_back(b);
        gph[b].push_back(a);
    }
    cin >> K;
    for (int i = 0, x;i<K;i++) {
        cin >> x;
        src.push_back(x);
    }
    bfs(gph, src);
    int mx = INT_MIN;
    for (int i = 0;i<MM;i++) {
        mx = max(dist[i], mx);
    }

    cout << mx << endl;
}
