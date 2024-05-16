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

const int MM = 1e4;
ll n, q, a[MM];
int tim[MM], lst = 0, sect = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 0;i<n;i++) {
        cin >> a[i];
        for (int j = lst;j<lst+a[i];j++) {
            tim[j] = sect;
        }
        lst += a[i]; sect++;
    }

    for (int i = 0,t;i<q;i++) {
        cin >> t;
        cout << tim[t] << endl;
    }
}

