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




int main() {


    vector<char> graph[26];

    map<char, int> map;


//    vector<char>& edge : graph)
    char c, d;

    int cnt = 0;
    while (true) {
        cin >> c >> d;
        if (c == '*') break;

        graph[c-'A'].push_back(d);
        graph[d-'A'].push_back(c);
        cnt++;
    }

    queue<char> q;

    bool visited[26];

    //

    vector<pair<char, char>> res;
    for (int i = 0;i<26;i++) {
        for (char ch :graph[i-'A']) {
            graph[i].erase(ch); bool canReach = false;
            visited[1] = true;
            q.push('B');
            while (!q.empty()) {
                char u = q.front(); q.pop();
                if (u == 'A') {canReach = true;}
                for (char ch :graph[u-'A']){
                    if (!visited[ch]) {
                        visited[ch] = true; q.push(ch);
                    }
                }
            }

            if (!canReach) {
                res.push_back({char(i+'A'), ch});
            }
            graph[i].push_back(ch);
        }


        // iterate through all edges and remove them one by one
        // run bfs a -> b
        // check if not reachable
        // then put the edge back and try another one.
    }

    for (pair<char, char> pcc: res) {
        cout << pcc.first <<  pcc.second << "\n";
    }

    cout << "There are " << res.size() << " disconnecting roads." << "\n";
}