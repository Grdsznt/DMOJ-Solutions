#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e6+3;
int N, a[MM]; long long ans=0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    for (int i = 0;i<N;i++) {
        cin >> a[i];
    }
    if (N % 2 == 0) {
        for (int i = 0;i<N-(N/2);i++) {
            if (a[i + N/2] == a[i]) ans += 2;
        }
    }

    cout << ans << "\n";
}