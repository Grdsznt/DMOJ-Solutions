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

const int MM = 5e5+2;
int n, q, a[MM], ans = INT_MIN, psa[MM], p2[MM];

unordered_map<int, int> mp;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1;i<=n;i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + (a[i] == a[i-1]);
        p2[i] = p2[i-1]; mp[a[i]] = i;
        if (mp.count(-a[i])) p2[i] = max(p2[i], mp[-a[i]]);
    }

    for (int i = 0, l, r;i<q;i++) {
        cin >> l >> r;
        cout << (psa[r] - psa[l] == r-l || p2[r] >= l ? "YES\n" : "NO\n");
    }

//    for (int i = 0;i<n;i++) {
//        for (int j = 1; j<n;i++) {
//            for (int k = i; k<=j;k++) {
//                s.insert(a[k]);
//            }
//        }
//    }
//    for (int i = 0, l, r;i<q;i++) {
//        cin >> l >> r; bool z = 0;
//        for (int j : zeros) {
//            if (j <= r && j >= l) {
//                cout << "YES\n";  z = 1;
//            }
//        }
//        if (z) continue;
//        z = 0;
//        for (int j = l;j<=r;j++) {
//            st.insert(a[j]); vec.push_back(a[j]);
//        }
//        if (st.size() == 1) {
//            cout << "YES\n"; st.clear(); vec.clear();
//            continue;
//        }
//        for (int k : st) {
//            for (int j = 0;j<vec.size();j++) {
//                vec[j] += k;
//                if (vec[j] == 0) {cout << "YES\n"; z = 1; break;}
//            }
//            if (z) break;
//        }
//        vec.clear(); st.clear();
//        if (z) continue;
//        else cout << "NO\n";
//    }
}

