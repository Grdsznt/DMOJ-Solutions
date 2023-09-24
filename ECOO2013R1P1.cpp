#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int n, m = 0, o=0; cin >> n;
    while (s != "EOF") {
        
        cin >> s;
        if (s == "TAKE") {
            if (n < 999) {
                n++;
            } else {
                n = 1;
            }
            m++;
        }else if (s == "SERVE") {
            o++;
        } else if (s == "CLOSE"){
            cout << m << " " << m-o << " " << n << endl;
            m = o = 0;
        }
        
    }
    

}