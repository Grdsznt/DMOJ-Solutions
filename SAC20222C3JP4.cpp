#include <bits/stdc++.h>
using namespace std;
int q;

int base10toany(int num, int base, vector<int> vec) {
    string actual = "";
    if (num == 0) {
        reverse(vec.begin(), vec.end());
        if (vec.empty()) {
            return 0;
        } else {
            for (int i = 0;i<vec.size();i++) {
                actual = actual + to_string(vec[i]);
            }
        }
        return stoi(actual);
    }
    int rem = num % base; int quot = num / base;
    vec.push_back(rem);
    base10toany(quot, base, vec);
    return stoi(actual);
}

int toBase10(string num, int base) {
    int actual = 0;
    int a[num.length()];
    for (int i = 0;i<num.length();i++) {
        a[i] = stoi(num.substr(i))*base^(num.length()-1-i);
    }
    for (int j = 0;j<sizeof(a);j++) {
        actual = actual + a[j];
    }
    return actual;
     
}
int convert(int base1, int num1, int base2) {
    vector<int> newvec;
    int num;
    if (base1 == 10) {
        num = base10toany(num1, base2, newvec);
    } else {
        int b10 = toBase10(to_string(num1), base1);
        num = base10toany(b10, base2, newvec);
    }
    return num;
}

int main() {
    cin >> q;
    int j, k, l;
    int print[q];
    for (int i = 0;i<q;i++) { cin >> j, k, l; print[i] = convert(j, k, l);}
    for (int m = 0;m<q;m++) {
        cout << print[m];
    }

}
