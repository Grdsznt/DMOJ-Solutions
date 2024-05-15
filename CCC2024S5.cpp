#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 2e5+3;
int N, a[3][MM];
//ll psa1[MM], psa2[MM], dp[1000][MM];

int main() {
    cin >> N;
    for (int i = 0;i<2;i++) {
        for (int j = 0;j<N;j++) {
            cin >> a[i][j];
        }
    }

//    for (int j = 1;j <= N;j++) {
//        psa1[j] = psa1[j - 1] + a[0][j - 1];
//        psa2[j] = psa2[j - 1] + a[1][j - 1];
//    }

//    for (int i = 1; i <= N; ++i) {
//        for (int j = i; j <= N; ++j) {
//            if (i == 1) {
//                dp[i][j] = (psa1[j] + psa2[j]) / ();
//            } else {
//                for (int k = i - 1; k < j; ++k) {
//                    if (static_cast<double>( psa2[j] - psa2[k+1]) / (j - k + 2) == static_cast<double> (psa1[k] - psa1[i-1]) / (k - i +1)) {
//                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
//                    }
//                }
//            }
//        }
//    }


    int s1 = (a[0][0] + a[1][0] == a[0][1] + a[1][1]) ?  2 : 1;
    int s2 = (a[0][0] + a[0][1] == a[1][0] + a[1][1]) ?  2 : 1;

    int s3 = (a[0][0] == a[1][0] && a[0][0] == a[1][1] && a[0][0] == a[0][1]) ? 4 : 1;

    int s4 = ((double)(a[0][0] + a[1][0]  + a[0][1]) / 3 == a[1][1]) ?  2 : 1;
    int s5 = ((double)(a[0][1] + a[1][0]  + a[1][1]) / 3 == a[0][0]) ?  2 : 1;
    int s6 = ((double)(a[0][0] + a[1][0]  + a[1][1]) / 3 == a[0][1]) ?  2 : 1;
    int s7 = ((double)(a[0][0] + a[0][1]  + a[1][1]) / 3 == a[1][0]) ?  2 : 1;
    int s8 = ((double) (a[0][0] + a[0][1]) / 2 == a[1][0] && (double) (a[0][0] + a[0][1]) / 2 == a[1][1]) ?  3 : 1;
    int s9 = ((double) (a[0][0] + a[1][0]) / 2 == a[0][1] && (double) (a[0][0] + a[1][0]) / 2 == a[1][1]) ?  3 : 1;
    int s10 = ((double) (a[0][1] + a[1][1]) / 2 == a[1][0] && (double) (a[0][1] + a[1][1]) / 2 == a[0][0]) ?  3 : 1;
    int s11 = ((double) (a[1][0] + a[1][1]) / 2 == a[0][0] && (double) (a[1][0] + a[1][1]) / 2  == a[0][1]) ?  3 : 1;





    cout << max({s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11});

//    int s1 = ((a[0][0] + a[1][0]) / 2.0 == (a[0][1] + a[1][1]) / 2.0) ? 2 : 1;
//    int s2 = ((a[0][0] + a[0][1]) / 2.0 == (a[1][0] + a[1][1]) / 2.0) ? 2 : 1;
//    int s3 = (a[0][0] == a[1][0] && a[0][0] == a[1][1] && a[0][0] == a[0][1]) ? 4 : 1;
//
//    int s4 = ((a[0][0] + a[1][0] + a[0][1]) / 3.0 == a[1][1]) ? 2 : 1;
//    int s5 = ((a[0][1] + a[1][0] + a[1][1]) / 3.0 == a[0][0]) ? 2 : 1;
//    int s6 = ((a[0][0] + a[1][0] + a[1][1]) / 3.0 == a[0][1]) ? 2 : 1;
//    int s7 = ((a[0][0] + a[0][1] + a[1][1]) / 3.0 == a[1][0]) ? 2 : 1;
//
//    cout << max({s1, s2, s3, s4, s5, s6, s7});
}
