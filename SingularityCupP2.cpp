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
string S;


// The 1st letter must be the same as the last letter to merge
// Check 1st letter, then if same count num of adjacent two letters which are the same
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    if (S[0] != S[N-1]) cout << N << "\n";
    else {
        int cnt = 1;
        for (int i = 1;i<N;i++) cnt += S[i] == S[i-1];
        cout << max(1, N-cnt) << endl;
    }
}

