#include <bits/stdc++.h>

using namespace std;

string s;
map<int, string> dict = {{0, "O"}, {1, "l"}, {3, "E"}, {4, "A"}, {5, "S"}, {6, "G"}, {8, "B"}, {9, "g"}};


int main() {
    cin >> s;
    string q = "";
    for (int c = 0;c<s.length();c++) {
        if (dict[s[c]] != "") {
            q = q + dict[s[c]];
        }
    }

    cout << q;
    
}