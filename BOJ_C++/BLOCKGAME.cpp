#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
char dp[1 << 25];
vector<int> moves;
int cell(int x, int y) {
    return 1 << (x * 5 + y);
}
void precalc() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            vector<int> cells;
            int sum = 0;
            for(int dx = 0; dx < 2; dx++) {
                for(int dy = 0; dy < 2; dy++) {
                    cells.push_back(cell(i + dx, j + dy));
                    sum += cell(i + dx, j + dy);
                }
            }
            for(int k = 0; k < 4; k++) {
                moves.push_back(sum - cells[k]);
            }
        }
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(j + 1 < 5) {
                moves.push_back(cell(i, j) + cell(i, j + 1));
            }
            if(i + 1 < 5) {
                moves.push_back(cell(i, j) + cell(i + 1, j));
            }
        }
    }
}
char go(int state) {
    char &ret = dp[state];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i < moves.size(); i++) {
        if((moves[i] & state) == 0) {
            if(go(state | moves[i]) == 0) {
                return ret = 1;
            }
        }
    }
    return ret;
}
void solve() {
    vector<string> a(5);
    int state = 0;
    for(int i = 0; i < 5; i++) {
        cin >> a[i];
        for(int j = 0; j < 5; j++) {
            if(a[i][j] == '#') {
                state += cell(i, j);
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    int tmp = go(state);
    cout << (tmp ? "WINNING" : "LOSING") << '\n';
}
int main() {
    fastio;
    precalc();
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}