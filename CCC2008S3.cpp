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


int t;

const int MM = 21;


bool isValid(int newi, int newj, char c[][MM], bool visited[][MM], int row, int col) {

    if (newi < row && newi >= 0 && newj >= 0 && newj < col) {
        if (!visited[newi][newj] && c[newi][newj] != '*') {
            return true;
        }
    }
    return false;

}


int main() {


    cin >> t;


    int di[] = { -1, 1, 0, 0 };
    int dj[] = { 0, 0, 1, -1 };


    for (int i = 0;i<t;i++) {
        int dist[MM][MM];
        char c[MM][MM]; int row, col;
        cin >> row >> col;
        for (int j = 0;j<row;j++) {
            for (int k = 0;k<col;k++) {
                char ch;
                cin >> ch;
                c[j][k] = ch;
            }

        }


        if (c[0][0] == '*' || c[row-1][col-1] == '*') {cout << -1 << endl; continue;}

        queue<pair<int, int>> q;
        // you can probably make a 2d array
        bool visited[MM][MM];



        for (int j = 0;j<row;j++) {
            for (int k = 0;k<col;k++) {
                dist[j][k] = 0;
                visited[j][k] = false;
            }
        }
        q.push({ 0, 0 }); visited[0][0] = true;
        while (!q.empty()) {
            pair <int, int> u = q.front(); q.pop();
            if (c[u.first][u.second] == '+') {
                for (int j = 0;j<4;j++) {
                    int newi = u.first + di[j];
                    int newj = u.second + dj[j];

                    if (isValid(newi, newj, c, visited, row, col)) {
                        visited[newi][newj] = true; q.push({newi, newj});
                        dist[newi][newj] = dist[u.first][u.second] + 1;
                    }
                }
            } else if (c[u.first][u.second] == '-') {
                for (int j = 2;j<4;j++) {
                    int newi = u.first + di[j];
                    int newj = u.second + dj[j];

                    if (isValid(newi, newj, c, visited, row, col)) {
                        visited[newi][newj] = true; q.push({newi, newj});
                        dist[newi][newj] = dist[u.first][u.second] + 1;
                    }
                }
            } else if (c[u.first][u.second] == '|') {
                for (int j = 0;j<2;j++) {
                    int newi = u.first + di[j];
                    int newj = u.second + dj[j];

                    if (isValid(newi, newj, c, visited, row, col)) {
                        visited[newi][newj] = true; q.push({newi, newj});
                        dist[newi][newj] = dist[u.first][u.second] + 1;
                    }
                }
            }

        }

        if (dist[row-1][col-1] == 0 && (row != 1 && col != 1)) {
            cout << -1 << endl;
        } else {
            cout << dist[row-1][col-1]+1 << endl;
        }
    }



}
