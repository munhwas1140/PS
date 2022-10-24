#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[50][101][101][101];
int go(int turn, int a, int b, int c) {
    if(a == b && b == c && c == 0) return 0;
    int &ret = dp[turn][a][b][c];
    if(ret != -1) return ret;
    
    if(a > 0)
        ret = max(ret, min(turn, a) - go(turn + 1, max(a - turn, 0), b, c));
    if(b > 0)
        ret = max(ret, min(turn, b) - go(turn + 1, a, max(b - turn, 0), c));
    if(c > 0)
        ret = max(ret, min(turn, c) - go(turn + 1, a, b, max(c - turn, 0)));
    
    return ret;
}
int main() {
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    memset(dp,-1,sizeof(dp));
    int sum = a + b + c;
    int ans = go(1, a, b, c);

    if(ans > 0) {
        cout << "F" << '\n';
    } else if(ans == 0) {
        cout << "D" << '\n';
    } else {
        cout << "S" << '\n';
    }

    return 0;
}