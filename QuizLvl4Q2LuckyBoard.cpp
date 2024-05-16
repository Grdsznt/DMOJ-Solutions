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

struct triple {
    ll f, s, t;
};
bool compareFrac(const triple f1, const triple f2) {
    if (f1.f * f2.s == f2.f * f1.s) {
        return f1.t < f2.t;
    }
    return f1.f * f2.s > f2.f * f1.s;
}


vector<triple> kids;
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1, x, y;i<=N;i++) {
        cin >> x >> y;
        kids.push_back({x, x+y, i});
    }

    sort(kids.begin(), kids.end(), compareFrac);

    for (triple trip: kids) {
        cout << trip.t << " ";
    }
    cout << endl;
}

