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

const int MM = 2e3 + 2;
ll n;
string res = "";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n > 0) {
        n--;
        char c = 'A' + (n % 26);
        res = c + res;
        n /= 26; // division method
    }

    cout << res << endl;
}

