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


int n, m;

const int MM = 1002;
int dist[MM][MM];

bool isValid(int newi, int newj, char c[][MM], bool visited[][MM]) {

    if (newi < n && newi >= 0 && newj >= 0 && newj < m) {
        if (!visited[newi][newj] && c[newi][newj] != 'X') {
            return true;
        }
    }
    return false;

}


int main() {


    cin >> n >> m;
    char c[MM][MM];

    int di[] = { -1, 0, 1, 0 };
    int dj[] = { 0, 1, 0, -1 };

    int sti = -1, stj = -1, endi = -1, endj = -1;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            char ch;
            cin >> ch;
            if (ch == 's') {
                sti = i; stj = j;
            } else if (ch == 'e') {
                endi = i; endj = j;
            }
            c[i][j] = ch;
        }
    }
    // bfs from st to end, distance between them is minimum dist
    queue<pair<int, int>> q;
     // you can probably make a 2d array
    bool visited[MM][MM];


    dist[sti][stj] = 0;
    q.push({ sti, stj }); visited[sti][stj] = true;
    while (!q.empty()) {
        pair <int, int> u = q.front(); q.pop();
        for (int i = 0;i<4;i++) {
            int newi = u.first + di[i];
            int newj = u.second + dj[i];

            if (isValid(newi, newj, c, visited)) {
                visited[newi][newj] = true; q.push({newi, newj});
                dist[newi][newj] = dist[u.first][u.second] + 1;
            }
        }
    }

    if (endi == -1 || sti == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[endi][endj]-1 << endl;
    }





}
