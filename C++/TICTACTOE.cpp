#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[19683];
int bijection(const vector<string> &board) {
    int ret = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            ret = ret * 3;
            if(board[i][j] == 'o') ret += 1;
            else if(board[i][j] == 'x') ret += 2;
        }
    }
    return ret;
}

bool isFinished(vector<string> &board, char turn) {
    string tmp(3, turn);
    if(board[0] == tmp || board[1] == tmp || board[2] == tmp) return true;
    
    for(int i = 0; i < 3; i++) {
        bool ok = true;
        for(int j = 0; j < 3; j++) {
            if(board[j][i] != turn) ok = false;
        }
        if(ok) return true;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == turn) return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == turn) return true;
    return false;
}
int canWin(vector<string> &board, char turn) {
    if(isFinished(board, 'o' + 'x' - turn)) return -1;

    int &ret = dp[bijection(board)];
    if(ret != -2) return ret;
    int minval = 2;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '.') {
                board[i][j] = turn;
                minval = min(minval, canWin(board, 'o' + 'x' - turn));
                board[i][j] = '.';
            }
        }
    }

    if(minval == 2 || minval == 0) return ret = 0;
    return ret = -minval;
}

void solve() {
    vector<string> a(3);
    int o, x;
    o = x = 0;
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
        for(int j = 0; j < 3; j++) {
            if(a[i][j] == 'o') o++;
            else if(a[i][j] == 'x') x++;
        }
    }
    for(int i = 0; i < 19683; i++) {
        dp[i] = -2;
    }
    char turn = (o == x ? 'x' : 'o');
    int tmp = canWin(a, turn);
    if(tmp == 0) {
        cout << "TIE" << '\n';
    } else if(tmp == 1) {
        cout << turn << '\n';
    } else {
        cout << char('o' + 'x' - turn) << '\n';
    }


}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}