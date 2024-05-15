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



string s, t;
int freq[27], freq2[27];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    int diff = 0, aster = 0;
    for (int i = 0;i<s.length();i++) {
        freq[s[i] - 'a']++;
    }
    for (int i = 0;i<t.length();i++) {
        if (t[i] == '*') aster++;
        else freq2[t[i] - 'a']++;
    }

    for (int i = 0;i<27;i++) {
        if (freq[i] != freq2[i]) {
            diff += abs(freq[i] - freq2[i]);
        }
    }

    if (diff == aster) cout << "A" << "\n";
    else cout << "N" << "\n";


}
