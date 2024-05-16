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

const int MM = 103;
int N, in[MM], out[MM], snk = 0, indx = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;

    for (int i = 0,a,b;i<N-1;i++) {
        cin >> a >> b;
        in[b]++; out[a]++;
    }
    bool snk = false;
    for (int i = 1;i<=N;i++) {
        if (snk && out[i] == 0 && in[i] > 0) {indx = -1; break;}
        if (out[i] == 0 && in[i] > 0) {
            snk = true; indx = i;
        }
    }

    cout << indx << "\n";

}