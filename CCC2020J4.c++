#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main() {
    string s,t;
    cin >> t >> s;
    for (int i = 0;i<s.size(); i++) {
        
        if (t.find(s) != -1) {
            cout << "yes" << endl;
            return 0;
        }
        s = s.substr(1) + s[0];
    }
    cout << "no" << endl;
}