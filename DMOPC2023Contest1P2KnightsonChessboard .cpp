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

    cin >> N;

    if (N % 5 == 1) {
        for (int i = 2;i<N;i+=5) {
            for (int j = 0;j<N;j++) {
                grid[i][j] = 1;
            }
        }
        int cnt = 0;
        for (int i = 2, j = N-3; i < N/2 && j >= N/2; i++, j--) {
            grid[N-2][i] = 1; cnt++;
            grid[N-2][j] = 1;
            if (cnt == 4) {
                i += 2; j -= 2;
            }
            cnt %= 4;
        }

        if (N % 2 == 1) {
            grid[N-2][(N-1)/2] = 1;
        } else {
            grid[N-2][(N-1)/2] = 1;
            grid[N-2][(N-1)/2+1] = 1;
        }


    } else if (N % 5 == 2) {
        for (int i = 2;i<N;i+=5) {
            for (int j = 0;j<N;j++) {
                grid[i][j] = 1;
            }
        }
        for (int i = 0; i < N;i++) {
            grid[N-3][i] = 1;
        }
    } else {
        for (int i = 2;i<N;i+=5) {
            for (int j = 0;j<N;j++) {
                grid[i][j] = 1;
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

