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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 1e6+2;
string s;
int n, t, freq[26], ans = INT_MIN;
vector<pii> seg;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for (int k = 0;k<t;k++) {
        cin >> n; cin >> s;
        int cur = 0, prev = 0;
        int mxl = 1;
        int len = 1;
        for (int i = 1;i<n;i++) {
            if (s[i] == s[i-1]) {
                len++;
            } else {
                len = 1;
            }
            mxl = max(mxl, len);
        }
        if (mxl != n) mxl++;
        for (int i = 1;i<n-1;i++) {
            if (s[i-1] == s[i+1]) {
                char c = s[i-1]; int j = i-1, k = i+1, l = 1, r = 1;
                while (j > 0 && s[j-1] == c) {
                    j--; l++;
                }
                while (k < n-1 && s[k+1] == c) {
                    k++; r++;
                }
                mxl = max(mxl, l+r+1);
            }
        }
        cout << mxl << "\n";
    }

}

