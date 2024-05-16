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

const int MM = 902;
int M;
unordered_map<string, int> mp;
vector<int> adj[2*MM];
string name[2*MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M; int node = 1;
    for (int i = 0;i<M;i++) {
        string a, b; cin >> a >> b;
        if (mp.find(a) != mp.end()) {mp[a] = node; name[node] = a; node++;}
        if (mp.find(b) != mp.end()) {mp[b] = node; name[node] = b; node++;}
        adj[mp[a]].push_back(mp[b]);
    }
}
