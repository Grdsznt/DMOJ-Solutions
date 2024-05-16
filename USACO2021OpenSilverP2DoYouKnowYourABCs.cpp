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


int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i = 1, N;i<=T;i++) {
        cin >> N; int arr[N], ans = 0; set<int> st;
        for (int j = 0;j<N;j++) {
            cin >> arr[j];
            st.insert(arr[j]);
        }

        for (int j = 0;j<N;j++) {
            for (int k = 1;k+j<N;k++) {
                st.insert(abs(arr[j+k] - arr[j]));
            }
        }

        for (int a: st) {
            for (int b: st) {
                for (int c: st) {
                    set<int> combs; bool val = true;
                    if (a > b || b > c || a > c) continue;
                    combs.insert(a); combs.insert(b); combs.insert(c);
                    combs.insert(a+b); combs.insert(b+c); combs.insert(c+a); combs.insert(a+b+c);
                    for (int j = 0;j<N;j++) {
                        if (combs.find(arr[j]) == combs.end()) {
                            val = false; break;
                        }
                    }
                    if (val) ans++;
                }
            }
        }

        cout << ans << endl;
    }
}