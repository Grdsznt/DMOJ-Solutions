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


int N;
vector<string> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0;i<4;i++) {
        string str; cin >> str;
        s.push_back(str);
    }

    for (int i = 0;i<N;i++) {
        string str; cin >> str;
        bool found = false;
        sort(s.begin(), s.end());
        do {
            bool val = true;
            for (int j = 0;j<str.size();j++) {
                if (s[j].find(str[j]) == string::npos) {
                    val = false; break;
                }
            }
            if (val) {found = true; break;}
        } while(next_permutation(s.begin(),s.end()));

        cout << (found ? "YES" : "NO")  << "\n";
    }

}