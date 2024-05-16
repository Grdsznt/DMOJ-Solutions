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


int N;
vector<ll> v[N];

int main() {


    cin >> N;

    int lo = INT_MAX, hi = INT_MIN;
    for (int i = 0, p, w, d;i<N;i++) {
        cin >> p >> w >> d;

        v[i].push_back(p); v[i].push_back(w); v[i].push_back(d);
        hi = max(hi, p);
        lo = min(lo, p);
    }

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


    cout << score << endl;

}
