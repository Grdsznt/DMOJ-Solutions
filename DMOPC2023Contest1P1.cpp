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

const int MM = 2e3 + 2;
int N, K, grid[MM][MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    if (K > N) cout << -1 << endl;

    int dia = N*N;
    for (int i = 0;i<K;i++) {
        grid[i][i] = dia;
        dia--;
    }
    for (int i = 0;i<N;i++) {
        for (int j = 0;j<N;j++) {
            if (grid[i][j] == 0) {
                grid[i][j] = dia; dia--;
            }
        }
    }

    for (int i = 0;i<N;i++) {
        for (int j = 0;j<N;j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}