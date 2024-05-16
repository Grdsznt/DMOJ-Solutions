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

const int MM = 1.5e3+2;


bool visited[MM][MM];
int grid[MM][MM], dist[MM][MM];

int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };

int N, M, K;

int main() {
    cin >> N >> M >> K;
    deque<pii> q;
    for (int i = 0;i<N;i++) {
        for (int j = 0;j<M;j++) {
            int n; cin >> n;
            if (n > 0) {
                q.push_back({i, j});
                visited[i][j] = true;
            }
            grid[i][j] = n;

            visited[i][j] = false;
        }
    }

    sort(q.begin(), q.end(), [&] (pii a, pii b) {return grid[a.first][a.second] < grid[b.first][b.second];});

    while (!q.empty()) {
        pii p = q.front(); q.pop_front();
        if (dist[p.first][p.second] == K) continue;
        for (int k = 0;k <4;k++) {
            int newi = p.first + di[k];
            int newj = p.second + dj[k];
            if ((newi < N && newi >= 0 && newj >= 0 && newj < M) && (grid[newi][newj] == 0 && !visited[newi][newj])) {
                grid[newi][newj] = grid[p.first][p.second];
                visited[newi][newj] = true; q.push_back({newi, newj});
                dist[newi][newj] = dist[p.first][p.second] + 1;
            }
        }
    }

    for (int i = 0;i<N;i++) {
        for (int j = 0;j<M;j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }



}