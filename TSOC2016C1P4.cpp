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

const int MM = 5e5 + 1;
int R, C;

bool visited[36][51];
int grid[36][51];

int main() {
    cin >> R >> C;
    int di[] = { -1, 0, 1, 0 };
    int dj[] = { 0, 1, 0, -1 };
    int ans = 0;
    for (int i = 0;i<R;i++) {
        for (int j = 0;j<C;j++) {
            char c; cin >> c;
            if (c == '#') grid[i][j] = 1;
            else if (c == 'M') grid[i][j] = 2;
            visited[i][j] = false;
        }
    }

    for (int i = 0;i<R;i++) {
        for (int j = 0;j<C;j++) {
            if (grid[i][j] != 1 && !visited[i][j]) {
                queue<pii> q; bool monkey = false;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    pii p = q.front(); q.pop();
                    if (grid[p.first][p.second] == 2) {monkey = true;}
                    for (int k = 0;k <4;k++) {
                        int newi = p.first + di[k];
                        int newj = p.second + dj[k];
                        if ((newi < R && newi >= 0 && newj >= 0 && newj < C) && (grid[newi][newj] != 1 &&!visited[newi][newj])) {
                            visited[newi][newj] = true; q.push({newi, newj});
                        }
                    }
                }
                if (monkey) ans++;
            }

        }
    }

    cout << ans << "\n";
}