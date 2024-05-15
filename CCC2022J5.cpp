//#include <bits/stdc++.h>
//#include <iostream>
//using namespace std;
//
///* TYPES  */
//#define ll long long
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define vi vector<int>
// #define vll vector<long long>
// #define mii map<int, int>
// #define si set<int>
// #define sc set<char>
//
//
//// /* INPUTS */
//// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
//
//// /* UTILS */
//// #define MOD 1000000007
//// #define PI 3.1415926535897932384626433832795
//// ll min(ll a,int b) { if (a<b) return a; return b; }
//// ll min(int a,ll b) { if (a<b) return a; return b; }
//// ll max(ll a,int b) { if (a>b) return a; return b; }
//// ll max(int a,ll b) { if (a>b) return a; return b; }
//// ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
//// ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
//// string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
//// string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
//// bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
//
//
//// /* TYPEDEF */
//// typedef long int int32;
//// typedef unsigned long int uint32;
//// typedef long long int int64;
//// typedef unsigned long long int  uint64;
//
//const int MM = 5e5 + 1;
//int N, T, grid[MM][MM];
//
//
//
//int main() {
//    vector<pii> v;
//
//    cin >> N >> T;
//    int ans;
//    for (int i = 0, x, y;i<T;i++) {
//        cin >> x >> y;
//        v.push_back({x, y});
//    }
//
//    sort(v.begin(), v.end());
//
//    for (int i = 0;i<N;i++) {
//        for (int j = 0;j<N;j++) {
//
//            if (grid[i][j] != 1) {
//                bool broke = false;
//                for (int size = 2;size<N;size++) {
//                    for (int r = i;r<size;r++) {
//                        for (int c = j;c<size;c++) {
//                            if (!(r < N && c < N && grid[r][c] != 1)) {
//                                broke = true; break;
//                            }
//                        }
//                        if (broke) break;
//                    }
//                    ans = max(ans, size);
//                    if (broke) break;
//                }
//
//
//            }
//        }
//    }
//    cout << ans << endl;
//}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int N, T, ans; vector<pi> a;
int main(){
    cin >> N >> T;
    for(int i=1, x, y; i<=T; i++) {
        cin >> x >> y; a.push_back({x, y});
    }
    a.push_back({0, 0}); a.push_back({N+1, N+1});
    for(int i=0; i<a.size(); i++){
        for(int j=i+1; j<a.size(); j++){
            int lft = min(a[i].first, a[j].first), rit = max(a[i].first, a[j].first);
            int wid = rit - lft - 1;
            vector<int> mid = {0, N+1};
            for(int k=0; k<a.size(); k++){
                if(a[k].first > lft && a[k].first < rit){
                    mid.push_back(a[k].second);
                }
            }
            sort(mid.begin(),  mid.end());
            for(int k=1; k<mid.size(); k++){
                int height = mid[k] - mid[k-1] - 1;
                ans = max(ans, min(wid, height));
            }
        }
    }
    cout << ans << endl;
}