#include <bits/stdc++.h>

using namespace std;



int main () {
    cin.tie(0)->sync_with_stdio(0); int N;
    cin >> N;
    
    for (int i = 0;i<N;i++) {
        int M; cin >> M;
        for (int j = 2;j<=sqrt(M);j++) {
            while (M % j == 0) {
                cout << j << " "; M /= j;
            }
        }
        if (M != 1) cout << M << endl;
        else cout << endl;
    }

}