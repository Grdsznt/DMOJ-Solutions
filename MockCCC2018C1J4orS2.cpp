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

const int MM = 2e5+3;
int N;
int a[37][37];
int freq[37];

int check() {
    for (int i = 0;i<N;i++) {
        for (int j = 0;j<N;j++) {
            if (freq[a[i][j]] == 0) freq[a[i][j]]++;
            else return 0;
        }
        memset(freq, 0, sizeof(freq));
    }
    for (int i = 0;i<N;i++) {
        for (int j = 0;j<N;j++) {
            if (freq[a[j][i]] == 0) freq[a[j][i]]++;
            else return 0;
        }
        memset(freq, 0, sizeof(freq));
    }
    bool r = true, c = true;
    for (int i = 1;i<N;i++) {
        if (a[0][i] < a[0][i-1]) { r = false; break; }
    }
    for (int i = 1;i<N;i++) {
        if (a[i][0] < a[i-1][0]) { c = false; break; }
    }
    if (r && c) return 2;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0;i<N;i++) {
        for (int j = 0;j<N;j++) {
            char c;
            cin >> c;
            if (c >= 65 && c <= 90) {
                a[i][j] = c - 55;
            } else {
                a[i][j] = c - '0';
            }
        }
    }

    int ans = check();
    if (ans == 1) {
        cout << "Latin" << endl;
    } else if (ans == 0) {
        cout << "No" << endl;
    } else {
        cout << "Reduced" << endl;
    }

}
