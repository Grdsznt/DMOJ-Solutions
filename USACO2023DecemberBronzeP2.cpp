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

const int MM = 1e5 + 2;

int N, ans = 0;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> s;
    vector<int> groups;
    int length = 0, l = -1, days = INT_MAX;
    bool grp = false;
    for (int i = 0;i<N;i++) {
        if (s[i] == '1') {
            if (l == -1) {
                l = i;
                grp = true;
                length++;
            } else {
                length++;
            }
            if (i == N - 1) {
                if (l == 0) {
                    days = min(days, (length - 1) / 2);
                    groups.push_back(length);
                } else {
                    days = min(days, length - 1);
                    groups.push_back(length);
                }
            }
        } else if (s[i] == '0'){
            if (l == 0) {
                days = min(days, length-1);
                groups.push_back(length);
            } else if (grp) {
                days = min(days, (length - 1) / 2);
                groups.push_back(length);
            }
            length = 0; l = -1;
            grp = false;
        }
    }

    for (int length:groups) {
        ans += ceil((double)length/(2*days+1));
    }

    cout << ans << endl;
}
