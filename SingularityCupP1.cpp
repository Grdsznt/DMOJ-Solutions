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
int N, a[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N; for (int i = 1;i<=N;i++) cin >> a[i];
    if (N <= 3) {
        for (int i = 1;i<=3;i++) {
            if (a[i] == N) {
                cout << i << " " << i << endl; return 0;
            }
        }
    }
    if (a[1] == 1) cout << 2 << " " << N << endl;
    else if (a[N] == 1) cout << 1 << " " << N-1 << endl;
    else cout << 1 << " " << N << endl;
}
