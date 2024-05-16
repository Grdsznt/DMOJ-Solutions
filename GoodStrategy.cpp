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

const int MM = 1e6+2;
int n, m, freq[MM];
set<pii> st; bool vis[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i<=n;i++) st.insert({freq[i], i});
    for (int i = 0, t, p;i<m;i++) {
        cin >> t >> p;
        if (t == 1) {vis[p] = true; st.erase({freq[p], p});}
        else {
            if (!vis[p]) {
                st.erase({freq[p], p});
                freq[p]--;
                st.insert({freq[p], p});
            }
        }
        if (st.empty()) cout << "Make noise" << "\n";
        else cout << st.begin()->second << " " << st.rbegin()->second << "\n";
    }
}
