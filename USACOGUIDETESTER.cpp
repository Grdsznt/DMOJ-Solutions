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

int N, shell[3], guess[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N; int ans = INT_MIN;
    for (int i = 0,a ,b, g;i<N;i++) {
        cin >> a >> b >> g;
        swap(shell[a-1], shell[b-1]);
        guess[g-1]++;
    }
    cout << max({guess[0], guess[1], guess[2]}) << "\n";

}
