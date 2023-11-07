#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main() {
    ll low = 1, high = (ll) 2e9;
    while (low <= high) {
        ll middle = floor((low + high)/2);
        cout << middle << endl;  cin >> s;
        if (s == "OK") {return 0;}
        else if(s == "FLOATS") {high = middle-1;}
        else {low = middle + 1;}
    }
    


}

// void generate_permutations(string s) {
//     int n = s.length();
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             string temp = s;
//             char c = temp[i];
//             temp[i] = temp[j];
//             temp[j] = c;
//             count++;
//             cout << temp << endl;
//         }
//     }        
// }

// int main() {
//     generate_permutations("aa");
// }
