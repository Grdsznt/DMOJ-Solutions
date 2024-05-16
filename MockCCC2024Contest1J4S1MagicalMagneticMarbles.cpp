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
int N,K, ans = 0;
int s[MM];
vector<pii> ms;
vector<int> mar, dist;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;

    char c;
    for (int i = 0;i<N;i++) {
        cin >> c;
        if (c == '1') s[i] = 1;
        if (s[i] == 1) {
            mar.push_back(i);
        }
    }
    for (int i = 1;i<mar.size();i++) {
        if (abs(mar[i] - mar[i-1]) == 1) {
            s[mar[i-1]] = 0;
            mar[i-1] = -1;
        }
    }

    int dis = 0; bool fst = false;
    for (int i = 0;i<N;i++) {
        if (s[i] == 1 && fst) {
            dist.push_back(dis);
            dis = 0;
            ans++;
        } else if (s[i] == 1 && !fst) {
            fst = true; ans++; dis = 0;
        }
        if (s[i] == 0) {
            dis++;
        }
    }
    if (K == 0) {
        cout << ans << "\n"; return 0;
    }
    if (dist.size() == 0) {
        cout << 1 << "\n"; return 0;
    }

    sort(dist.begin(), dist.end());

    for (int i : dist) {
        if (K - i < 0) break;
        K -= i;
        ans--;
    }

    cout << ans << "\n";

}

