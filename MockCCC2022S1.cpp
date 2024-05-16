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

const int MM = 902;
int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int i = 0, a, b, c;i<T;i++) {
        cin >> a >> b >> c;
        if (a > c) {
            a = a-c;
            if (a % 2 == 1) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else if (a == c) {
            if (b % 2 == 0) {
                cout << "YES" << endl;
            } else if (b % 2 == 1 && c > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }







//
//        if (a == 0 && b == 0 && c == 0) {cout << "NO" << endl; return 0;}
//        if (((a+b+c) % 2 == 0) && (a >= c) && (b % 2 == 0 || a >= 1)) cout << "YES" << endl;
//        else cout << "NO" << endl;
//        b %= 2;
//        if (a == c && b == 0) cout << "YES" << endl;
//        else if (a % 2 == 0 && a-c > 0) cout << "YES" << endl;
//        else cout << "NO" << endl;


//        if (a % 2 == 0 && b % 2 == 0 && c == 0) cout << "YES" << endl;
//        else if (a % 2 == 1 && c % 2 == 1 && c <= a && b % 2 == 0) cout << "YES" << endl;
//        else if (a == c && b % 2 == 0) {cout << "YES" << endl;}
//        else if (a % 2 == 0 && c % 2 == 0 && b % 2 == 0) cout << "YES" << endl;
//        else if (a % 2 == 0 && b % 2 == 1 && a >= 2 && c == 0) cout << "YES" << endl;
//        else if (a % 2 == 1 && b % 2 == 1 && a >= 2 && (a-2) == c) cout << "YES" << endl;
//        else cout << "NO" << endl;
    }
}
