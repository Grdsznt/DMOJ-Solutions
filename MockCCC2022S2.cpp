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
int N; ll swaps = 0; string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> s;
    for (int i = 0, j = 0;i<2*N;i++) {
        if (s[i] == 'I') {swaps += abs(i - j); j += 2;}
    }
    cout << swaps << endl;
}
