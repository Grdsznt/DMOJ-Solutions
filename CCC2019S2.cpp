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

int T;
bool prime[2000001];
vector<int> primes;

void sieve (int n) {
    memset(prime, true, sizeof(prime));
    for (int i = 2;i * i<=n;i++) {
        if (prime[i])  {
            for (int j = i*i;j<=n;j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {

    cin >> T;
    sieve(2000000);
    for (int i = 0, N;i<T;i++) {
        cin >> N;
        if (prime[N]) {
            cout << N << " " << N << "\n";
        } else {
            for (int j = 2, a, b;j<=2*N;j++) {
                a = j; b = 2*N-j;
                if (prime[a] && prime[b] && a+b == 2*N) {
                    cout << a << " " << b << "\n";
                    break;
                }
            }
        }
    }
}