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

const int MM = 2e5+3;
int N, a[MM], freq[MM], ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0;i<N;i++) {
        cin >> a[i]; freq[a[i]]++;
    }
    for (int i = 0;i<N;i++) {
        ans = max(freq[i], ans);
    }
    cout << ans << "\n";
}