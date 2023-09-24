#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

int board[9][9]; bool row[9][10], col[9][10], block[9][10]; vector<pi> vec;


char c;
int solve(int indx) {
    if (indx == vec.size()) {return true;}
    int r = vec[indx].first, c = vec[indx].second;
    for (int i = 1;i<=9;i++) {
        if (!row[r][i] && !col[c][i] && !block[3*(r/3) + (c/3)][i]) {
            board[r][c] = i;
            row[r][i] = col[c][i] = block[3*(r/3) + (c/3)][i] = true;
            if (solve(indx+1)) return true;
            row[r][i] = col[c][i] = block[3*(r/3) + (c/3)][i] = false;
        }
    }
    return false;

}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i =0;i<9;i++) {
        for(int j = 0; j<9;j++) {
            cin >> c;
            if (c != '.') {
                board[i][j] = c - '0';
                row[i][board[i][j]] = col[i][board[i][j]] = block[i][board[i][j]] = true;
            } else {
                vec.push_back({i, j});
            }
        }
    }
    solve(0);
    for (int i =0;i<9;i++) {
        for(int j = 0; j<9;j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

}