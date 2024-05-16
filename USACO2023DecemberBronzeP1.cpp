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

const int MM = 2e5+2;

ll N, M, cows[MM], candy[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i =0;i<N;i++) {
        cin >> cows[i];
    }
    for (int i = 0;i<M;i++) cin >> candy[i];

    for (int c = 0;c<M;c++) {
        ll bottom = 0;
        for (int i = 0;i<N;i++) {
            if (cows[i] > candy[c] && bottom < candy[c]) {
                cows[i] += candy[c]-bottom;
                break;
            } else if (cows[i] > bottom){
                ll eat = cows[i]-bottom;
                cows[i] += eat;
                bottom += eat;
            }
        }
    }
    for (int i =0;i<N;i++) {
        cout << cows[i] << endl;
    }

}