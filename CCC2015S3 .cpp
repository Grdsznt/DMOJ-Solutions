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
int G, P, ans = 0;
vector<int> gates;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> G >> P;
    for (int i = 1;i<=G;i++) {
        gates.push_back(i);
    }
    for (int i = 1, gi;i<=P;i++) {
        cin >> gi;
        int lo = 0, hi = gates.size()-1;
        int indx = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2; // binary search the locations that you can put the plane
            if (gates[mid] == gi) { // so if middle of the free gates is the right most it can dock in
                indx = mid; break; // set indx to flag to mark answer
            } else if (gates[mid] < gi) { // if it's less than right most for the gates middle, then search higher
                indx = mid; lo = mid+1;
            } else {
                hi = mid-1; // if it's greater, than search lower
            }
        }
        if (indx != -1) { // if has been marked, or plane has been docked, then ++ans
            ans++;
            gates.erase(gates.begin() + indx); // remove a free slot from the plane
        }
        else break; // if a plane couldn't be docked, shut down the station
    }
    cout << ans << endl;
}
