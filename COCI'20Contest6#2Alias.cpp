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

const int MM = 1e3+2;
int n, m, q, indx = 0;
ll dist[MM][MM];
map<string, int> mp;

int geti(string u) {
    if (mp.find(u) == mp.end()) {
        mp[u] = indx++;
    }
    return mp[u];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            if (i != j) dist[i][j] = LLONG_MAX;
        }
    }
    for (int i = 0,w;i<m;i++) {
        string x, y;
        cin >> x >> y >> w;
        int a = geti(x), b = geti(y);
        dist[a][b] = min((ll)w, dist[a][b]);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    cin >> q;
    for (int i = 0;i<q;i++) {
        string x, y;
        cin >> x >> y;
        if (dist[mp[x]][mp[y]] != LLONG_MAX) cout << dist[mp[x]][mp[y]] << "\n";
        else cout << "Roger\n";
    }
}

