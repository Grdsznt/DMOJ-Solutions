#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

#pragma GCC optimize "Ofast"
#pragma GCC target "avx2"

const int MM = 1e4+3;
int T, N, freq[27];
string s[MM];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T >> N;

    for (int i = 0;i<T;i++) {
        cin >> s[i];
    }

    for (int i = 0;i<T;i++) {
        for (int j = 0;j<N;j++) {
            freq[s[i][j] - 'a']++;
        }
        bool v = true;
        for (int j = 0;j<N-1;j++) {
            if (freq[s[i][j]-'a'] == 1 && freq[s[i][j+1]-'a'] < 2) {
                cout << "F\n"; v = false; break;
            }
            if (freq[s[i][j]-'a'] >= 2 && freq[s[i][j+1]-'a'] != 1) {
                cout << "F\n"; v = false; break;
            }
        }
        if (v) {
            cout << "T\n";
        }
        memset(freq, 0, sizeof(freq));
    }


}