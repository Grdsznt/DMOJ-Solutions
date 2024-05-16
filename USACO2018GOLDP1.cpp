#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* TYPES  */
#define ll long long
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define vi vector<int>
// #define vll vector<long long>
// #define mii map<int, int>
// #define si set<int>
// #define sc set<char>


// /* INPUTS */
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

// /* UTILS */
// #define MOD 1000000007
// #define PI 3.1415926535897932384626433832795
// ll min(ll a,int b) { if (a<b) return a; return b; }
// ll min(int a,ll b) { if (a<b) return a; return b; }
// ll max(ll a,int b) { if (a>b) return a; return b; }
// ll max(int a,ll b) { if (a>b) return a; return b; }
// ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
// ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
// bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }


// /* TYPEDEF */
// typedef long int int32;
// typedef unsigned long int uint32;
// typedef long long int int64;
// typedef unsigned long long int  uint64;


const int MM = 1e5+2;
int N, ans = INT_MIN;
vector<pair<int, int>> nums;
ll bit[MM];

void upd(int pos, int val) {
    for (int i = pos+1; i<MM;i += i&-i) {
        bit[i] += val;
    }
}

int qry(int pos) {
    int ret = 0;
    for (int i = pos+1; i; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}


int main() {

    cin >> N;
    for (int i = 0, j;i<N;i++) {
        cin >> j;
        nums.push_back({j, i});
    }

    sort(nums.begin(), nums.end()); // no need for customized comparator because auto sort by first ele
    for (int i = 0;i<N;i++) {
        upd(nums[i].second, 1);
        ans = max(ans, i+1 - qry(i));
    }

    cout << (ans == 0 ? 1 : ans) << endl;
}