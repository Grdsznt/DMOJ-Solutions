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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 5e5+2;
int n;
vector<int> zeros, vec;
ll bit[MM], ans = 0;

vector<array<int, 4>> events;

void upd(int pos, int val) {
    for(int i=pos; i<=n; i+=i&-i) bit[i] += val;
}

ll qry(int pos) {
    ll sum = 0;
    for (int i = pos;i>0;i-=i&-i) {
        sum += bit[i];
    }
    return sum;
}
// qry(r) - qry(l-1);


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0,x1,y1,x2,y2;i<n;i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
    }
    sort(events.begin(), events.end());
    for (int i =0;i<events.size();i++) {
        int a[] = events[i];
        upd(e[], p[4]); upd(p[2]+1, p[4]);
    }
    for (array<int, 4> p: events) {

        upd(p[1], p[4]); upd(p[2]+1, p[4]);

    }
}

