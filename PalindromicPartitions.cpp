#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
int N; ll memo[65];

ll f (int n) {
    if (memo[n] != 0) return memo[n];
    if (n<=1) return memo[n] = 1;
    ll ans = 1;
    for (int i = n-2;i>=0; i-= 2) {
        ans += f(i);
    }
    return memo[n] = ans;
}

// int countPalindromicPartitions(int n, vector<int>& partition) {
//     if (n == 0) { // base case
//         int len = partition.size();
//         bool isPalindrome = true;
//         for (int i = 0; i < len / 2; i++) {
//             if (partition[i] != partition[len - i - 1]) {
//                 isPalindrome = false;
//                 break;
//             }
//         }
//         if (isPalindrome) {
//             return 1; // Found a palindromic partition
//         } else {
//             return 0;
//         }
//     }
//     int count = 0;
//     int start = (partition.empty()) ? 1 : partition.back(); // only start from numbers >= previous number
//     for (int i = start; i <= n; i++) {
//         partition.push_back(i);
//         count += countPalindromicPartitions(n - i, partition);
//         partition.pop_back();
//     }
//     return count;
// }

int main() {
    cin >> N;
    
    int count = f(N);
    cout << count;
    return 0;
}



