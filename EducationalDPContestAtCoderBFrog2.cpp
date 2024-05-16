#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e5+3;
int N, K, a[MM], b[MM], first[MM], dp[MM];

vector<pii> rit, lft, seg;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 1;i<=N;i++) cin >> a[i];
    // dp state dp[i] is min cost to jump from stone 1 to stone i
    dp[1] = 0;

    for (int i = 1;i<=N;i++) {
        for (int j = 1;i<=K;j++) {
            a[i-1] = dp[i]
        }
    }
}
