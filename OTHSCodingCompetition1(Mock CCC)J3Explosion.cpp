#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e6+3;
int N, D, a[MM], mx = INT_MIN, ans = 0;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> D;
    for (int i = 0;i<N;i++) {
        cin >> a[i];
    }
    bool in = false, t = false; int e = 0;
    for (int i = 0;i<N-1;i++) {
        if (abs(a[i]-a[i+1]) <= D) {
            if (in) e++;
            else {
                e += 2; in = true;
            }
            mx = max(mx, e);
        } else {
            ans++;
            mx = max(mx, e);
            in = false; e = 0;
        }
    }
    ans++;

    cout << ans << "\n";
    cout << mx << "\n";

}
