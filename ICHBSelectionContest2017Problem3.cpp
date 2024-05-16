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


#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e5+1;
int N, Q;
ll bit[MM];

void upd(ll pos, ll val) {
    for (ll i = pos;i<MM;i += (i&-i)) {
        if (bit[i]) bit[i] = bit[i] & val;
        else bit[i] = val;//
    }
}

ll qry(ll pos) {
    ll ans = bit[pos];
    for (ll i = pos; i>0; i -= (i & -i)) ans &= bit[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N  >> Q;
    for (int i = 1;i<=N;i++) {
        ll x;
        cin >> x;
        upd(i, x);
    }

    for (int i = 0;i<Q;i++) {
        char c; cin >> c;
        if (c == 'U') {
            ll x, val; cin >> x >> val;
            upd(x, val);
        } else {
            ll x, y, val; cin >> x >> y >> val;
            cout << ((qry(y) - qry(x-1)) & val) << endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 1e5+5;
int N, Q; ll a[MM], t[4*MM], val; char op;
void build(int l, int r, int rt){
    if(l == r) { t[rt] = a[l]; return;}
    int m = (l + r)/2;
    build(l, m, lc); build(m+1, r, rc);
    t[rt] = (t[lc] & t[rc]);
}
void upd(int l, int r, int pos, ll val, int rt){
    if(l == r) { t[rt] = val; return; }
    int m = (l + r)/2;
    pos <= m? upd(l, m, pos, val, lc) : upd(m+1, r, pos, val, rc);
    t[rt] = (t[lc] & t[rc]);
}
ll qry(int l, int r, int ql, int qr, int rt){
    if(ql == l && qr == r) return t[rt];
    int m = (l + r)/2;
    if(qr <= m) return qry(l, m, ql, qr, lc);
    else if(ql > m) return qry(m+1, r, ql, qr, rc);
    else return (qry(l, m, ql, m, lc) & qry(m+1, r, m+1, qr, rc));
}
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> a[i];
    build(1, N, 1);
    for(int i=1, x, y; i<=Q; i++) {
        cin >> op;
        if(op == 'U') {
            cin >> x >> val; upd(1, N, x, val, 1);
        }else {
            cin >> x >> y >> val;
            cout << (qry(1, N, x, y, 1) & val) << "\n";
        }
    }

}
