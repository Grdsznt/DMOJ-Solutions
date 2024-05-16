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
//
//const int MM = 1e6+2;
//int N, ans = 0, freqr[MM], freqb[MM];
//char s[MM];
//vector<int> g;
//
//
//int main(){
//    ios::sync_with_stdio(0); cin.tie(0);
//    cin >> N;
//    for (int i = 0;i<N;i++) {
//        cin >> s[i];
//        if (s[i] == 'G') g.push_back(i);
//        if (s[i] == 'R') freqr[i]++;
//        if (s[i] == 'B') freqb[i]++;
//        if (i != 0) {
//            freqr[i] = freqr[i-1];
//            freqb[i] = freqb[i-1];
//        }
//    }
//    // the number of rgb words are the number of r's * num b's from the current g to the next g
//    for (int i = 1;i<g.size()-1;i++) {
//        ans += (freqr[g[i]] - freqr[g[i-1]]) * (freqb[g[i+1]] - freqb[g[i]]);
//    }
//    ans += (freqr[g[0]]) * freqb[g[0]];
//    ans += (freqr[g[g.size()-1]]) * freqb[g[g.size()-1]];
//
//
//    cout << ans << "\n";
//}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MM = 1e6+2;
ll N, ans = 0, freqr[MM], freqb[MM];
char s[MM];
vector<int> g;

int main() {

    cin >> N;

    for (int i = 0;i<N;i++) {
        cin >> s[i];
        if (s[i] == 'G') {
            g.push_back(i);
        }
        if (i != 0) {
            freqr[i] = freqr[i-1];
            freqb[i] = freqb[i-1];
        }
        if (s[i] == 'R') {
            freqr[i]++;
        }
        if (s[i] == 'B') {
            freqb[i]++;
        }
    }
    if (g.size() == 1) {
        cout << freqr[g[0]] * freqb[N-1] - freqb[g[0]] << endl;  return 0;
    }
    for (int i = 0; i < g.size(); i++) {
        //get the number of g's before you and b's after you
        int r, b;
        if (i == 0) {
            r = freqr[g[i]]; b = freqb[g[i+1]] - freqb[g[i]-1];
        } else if (i == g.size() - 1) {
            r = freqr[g[i]] - freqr[g[i-1]-1]; b = freqb[N-1] - freqb[g[i]-1];
        } else {
            r = freqr[g[i]] - freqr[g[i-1]-1]; b = freqb[g[i+1]] - freqb[g[i]-1];
        }
        ans += r*b;
//        int currG = g[i];
//        int prevG = (i == 0) ? -1 : g[i - 1];
//        int nextG = (i == g.size() - 1) ? N : g[i + 1];
//
//        int rCount = (prevG == -1) ? freqr[currG] : freqr[currG] - freqr[prevG];
//        int bCount = (nextG == N) ? freqb[N - 1] - freqb[currG] : freqb[nextG - 1] - freqb[currG];
    }
    cout << ans << "\n";
}

