#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0;i<t;i++) {
        long n, s, sol = 0;
        cin >> n; cin >> s;
        long sum = (n*(n+1)/2) - s;
        for (long j = 1;j<=(n+1);j++) {
            long k = sum-j;
            if (k <= n && j < k) ++sol;
        }
        cout << sol;
        cout << endl;
    }

}

