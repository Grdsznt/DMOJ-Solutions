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


int N;

int a[101][101], temp[101][101];

void rotate () {
     for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(a[i][j], a[j][i]);
        }
     }

    // Reverse each row to get the clockwise rotation
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N/2; j++) {
            swap(a[i][j], a[i][N-j-1]);
        }
    }
}

bool check() {
    for (int i = 0;i<N;i++) {
        for (int j = 0;j<N;j++) {
            if (j > 0 && a[i][j] < a[i][j-1]) return false;
        }
    }
    for (int i = 0;i<N;i++) {
        for (int j = 0;j<N;j++) {
            if (j > 0 && a[j][i] < a[j-1][i]) return false;
        }
    }

    return true;
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0;j<N;j++) {
            cin >> a[i][j];
        }

    }


    for (int i = 0;i<4;i++) {
        if (!check()) rotate();
        else break;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0;j<N;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
