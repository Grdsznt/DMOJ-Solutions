#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, N, mx = 0, sum = 0;
    bool stop = false;
    cin >> L;
    cin >> N;
    int* da = new int[L+1]();
    int s, t;
    for (int i = 0;i<N;i++) {
        cin >> s >> t;
        da[s]++; da[t]--;
    }
    for (int i = 1;i<=L;i++) {
        da[i] = da[i-1] + da[i];
    }
    for (int i = 0;i<L+1;i++) {
        if (da[i] == 0 && i != L) {++sum; stop = false;}
        else if (stop) {sum = 0;}
        else stop = true;
        mx = max(sum, mx);
    }
    delete[] da;
    
    cout << mx << endl;
    
}