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
int N, a[MM], cnt = 0, X;
ll c[MM], xsum = 0, xes = 0;
unordered_map<string, int> memo;


bool sorted(int l, int r) {
    for (int i = l; i < r; ++i) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

int minC(int l, int r) {

    if (l >= r || sorted(l, r)) {
        return 0;
    }
    string k = to_string(l) + "," + to_string(r);
    if (memo.find(k) != memo.end()) {
        // If result is in memo, return it
        return memo[k];
    }

    int ans = INT_MAX; vector<int> orig(a + l, a + r);
    for (int i = l; i <= r; ++i) {
        for (int j = i; j <= r; ++j) {
            sort(a + i, a + j + 1);
            int cost = i-j+1 + minC(l, r);
            ans = min(ans, cost);
            copy(orig.begin(), orig.end(), a + l);
        }
    }

    memo[k] = ans;
    return ans;

}

string vecToString(const vector<int>& vec) {
    string result;
    for (int num : vec) {
        result += to_string(num) + ",";
    }
    return result;
}

// Check if the permutation is already sorted
bool isSorted(const vector<int>& perm) {
    for (size_t i = 1; i < perm.size(); ++i) {
        if (perm[i - 1] > perm[i]) {
            return false;
        }
    }
    return true;
}

// Calculate the cost of sorting a subarray
int calculateCost(int l, int r) {
    // Placeholder for actual cost calculation; adjust as needed
    return r - l + 1;
}

// Sorts a subarray of the permutation
vector<int> sortSubarray(const vector<int>& perm, int l, int r) {
    vector<int> newPerm = perm;
    sort(newPerm.begin() + l, newPerm.begin() + r + 1);
    return newPerm;
}

// Recursive function with memoization to find the minimum cost to sort the permutation
int minCostToSortMemo(vector<int>& perm, unordered_map<string, int>& memo) {
    string key = vecToString(perm);
    if (memo.find(key) != memo.end()) {
        // If result is in memo, return it
        return memo[key];
    }
    if (isSorted(perm)) {
        return 0;
    }

    int minCost = numeric_limits<int>::max();
    int N = perm.size();
    for (int l = 0; l < N; ++l) {
        for (int r = l; r < N; ++r) {
            int cost = calculateCost(l, r);
            vector<int> newPerm = sortSubarray(perm, l, r);
            minCost = min(minCost, cost + minCostToSortMemo(newPerm, memo));
        }
    }
    // Save result in memo before returning
    memo[key] = minCost;
    return minCost;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for (int i = 1;i<=N;i++) {
        cin >> a[i];
    }
    cout << minCostToSortMemo() << "\n";
}

