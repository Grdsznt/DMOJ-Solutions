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

const int MM = 1e5+3;
ll n, q, c, ans = 0, dist[MM], dist2[MM];
int t, a[MM], bit[MM], status[MM], dif[MM];
vector<pii> adj[MM];

void upd(int pos, int val) {
    for (int i = pos;i<=n;i+=i&-i) {
        bit[i] = max(bit[i], val);
    }
}

int qry(int pos) {
    int mx = INT_MIN;
    for (int i = pos;i>0;i-=i&-i) {
        mx = max(mx, bit[i]);
    }
    return mx;
}

vector<pii> cons;
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> q >> c; bool v = true;
        for (int i=1;i<=n;i++) {
            cin >> a[i]; upd(i, a[i]);
        }
        if (a[1] == 0) {
            a[1] = 1; upd(1, 1);
        }
        for (int i = 0, x, y;i<q;i++) {
            cin >> x >> y; cons.push_back({x, y});
            if (x+1 <= y-1) {
                dif[x+1]++; dif[y-1]--;
            }
            status[x] = 1;

//            int mx = qry(x);
//            if (a[y] > mx) continue;
//            else if (a[y] < mx && a[y] != 0) {
//                cout << -1 << "\n"; v = 0; break;
//            } else {
//                if (mx < c) {
//                    a[y] = mx + 1;
//                    upd(y, mx+1);
//                } else {
//                    cout << -1 << "\n"; v = 0; break;
//                }
//            }

            // issue is it only gets modified as the query ranges come in.

            // query max from 1 - > x
            // if a[y] is already filled and greater than max
            // skip
            // but if a[y] does not fulfill req, -1
            // if a[y] is 0, fill with next larger number <= c
            // otherwise, -1
            //
        }

//        if (v) {
//            for (int i = 1;i<=n;i++) {
//                if(a[i] == 0) a[i] = 1;
//            } // change this what if all 0 0 0 0 0 0
//            // after all q, check if there still contains nums with 0, then fill with 1.
//            for (int i = 1;i<=n;i++) {
//                (i != n ? cout << a[i] << " " :  cout << a[i] << "\n");
//            }
//        }
//        memset(bit, 0, sizeof(bit));
        for (int i = 1;i<=n;i++) {
            dif[i] += dif[i-1];
            if (dif[i] > 0) {
                if (status[i] > 0) {cout << -1 << "\n"; return 0;}
                status[i] = -1;
            }
        }
        int mx = 0, last = 0;

        for (int i = 1;i<=n;i++) {
            if (status[i] == 1) {
                if (a[i] == 0) {
                    a[i] = mx + 1; last = i;
                }
            } else if (status[i] == -1) {

                if (a[i] == 0) {a[i] = 1;}
                else if (a[i] > mx) {
                    if (!last) {cout << "-1\n"; return 0 ;}
                    a[last] = a[i];
                }
            } else {
                if (a[i] == 0) {a[i] = 1; last = i;}
            }
        }
    }
    // starts at 1 ends at n

}
