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

const int MM = 1e5+1;
int N,K,T,ans = 0, a[MM], print[MM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> T;
    for (int i = 0;i<K;i++) {
        cin >> a[i];
    }


    for (int i =0;i<K;i++) {
        for (int j = 0; j < N; j++) {
            int d = a[i+1] - a[i];
            int pos = (int) (j + ceil((T - (j - a[i]))/d) * d) % N;
            cout << d << " " << pos << " i: " << i << " j: " << j << endl;
            print[pos] = j;
        }
    }

    for (int i = 0;i<N;i++) cout << print[i] <<" \n"[i == N-1];
}
