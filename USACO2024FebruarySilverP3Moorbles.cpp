#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 3e5+5, inf = 0x3f3f3f3f;
int T, N, M, K, even[MM], odd[MM], suf[MM]; // suffix arr
int main() {
    for (cin >> T; T--;) {
        memset(even, 0x3f, sizeof(even));
        memset(odd, 0x3f, sizeof(odd));
        memset(suf, 0, sizeof(suf));
        cin >> N >> M >> K;
        for (int i = 1;i<=M;i++) {
            int mi = inf;
            for (int k = 1, x;k<=K;k++) {
                // for all k options of marbles, take the abs min.
                // if cur opt is even, take worst case even, otherwise, worst case odd
                cin >> x; mi = min(mi, x);
                if (x%2) even[i] = min(even[i], -x);
                else odd[i] = min(odd[i], -x);
            }
            if (even[i] == inf) even[i] = mi;
            if (odd[i] == inf) odd[i] = mi;
        }
        for (int i = M;i>=1;i--) {
            suf[i] = min(0, suf[i+1] + max(even[i], odd[i])); // get suffix arr
        }
        if (N+suf[1] <= 0) {cout << "-1\n"; continue;} // if not even possible to get pos marbles, impossible
        int psa = N; // cumulative sum of marble loss
        for (int i = 1;i<=M;i++) {
            if (psa+even[i]+suf[i+1] > 0) {
                cout << "even\n"; psa += even[i]; // can you take even? if yes, take since lexo min
            }else{
                cout << "odd\n"; psa += odd[i]; // otherwise take odd
            }
        }
        cout << "\n";
    }
}


