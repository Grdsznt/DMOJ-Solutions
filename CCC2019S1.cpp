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

int flip[2][2] = {{1, 2}, {3, 4}};
string s;
int main() {

    cin >> s;
    for (int i = 0;i<s.length();i++) {
        if (s[i] == 'H') {
            int temp = flip[0][0];
            flip[0][0] = flip[1][0];
            flip[1][0] = temp;
            temp = flip[0][1];
            flip[0][1] = flip[1][1];
            flip[1][1] = temp;
        } else {
            int temp = flip[0][0];
            flip[0][0] = flip[0][1];
            flip[0][1] = temp;
            temp = flip[1][0];
            flip[1][0] = flip[1][1];
            flip[1][1] = temp;
        }
    }

    for (int i = 0;i<2;i++) {
        for (int j = 0;j<2;j++) {
            cout << flip[i][j] << " ";
        }
        cout << endl;
    }

}