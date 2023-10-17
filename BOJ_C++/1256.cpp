#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m, k;
int dp[101][101];
int go(int x, int y) {
    if(x == 0 && y == 0) return dp[x][y] = 1;
    
    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = 0;
    if(x > 0) ret += go(x-1,y);
    if(y > 0) ret += go(x,y-1);
    if(ret > 1000000000) ret = 1000000000;
    return ret;
}
void tracking(int x, int y, int k) {
    if(x == 0 && y == 0) return ;
    
    if(go(x-1,y) < k) {
        cout << 'z';
        tracking(x,y-1,k - dp[x-1][y]);
    } else {
        cout << 'a';
        tracking(x-1,y,k);
    }
}
int main() {
    fastio;
    cin >> n >> m >> k;
    memset(dp,-1,sizeof(dp));
    go(n,m);
    if(k > dp[n][m]) return !(cout << -1 << '\n');
    tracking(n,m,k);
      
    return 0;
}