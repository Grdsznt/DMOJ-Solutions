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

const int MM = 5e5 + 3;

int n;
vector<pii> points;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0,a,b;i<n;i++) {
        cin >> a >> b;
        points.push_back({a,b});
    }
    ll add = 0, sub = 0;
    for (int i = 0;i<n;i++) {
        add += points[i].first*points[(i+1)%n].second;
        sub += points[i].second*points[(i+1)%n].first;
    }

    cout << ceil(abs(add-sub)/(double)2) <<  endl;

}