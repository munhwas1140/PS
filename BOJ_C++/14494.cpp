#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m;
int dp[1001][1001];
const int mod = 1e9 + 7;
int go(int x, int y) {
    if(x == 1 || y == 1) return 1;
    
    int &ret = dp[x][y];
    if(ret != -1) return ret;
    ret = 0; 
    ret += go(x - 1, y - 1); ret %= mod;
    ret += go(x - 1, y); ret %= mod;
    ret += go(x, y - 1); ret %= mod;
    return ret ;
}
int main() {
    fastio;
    cin >> n >> m;
    memset(dp,-1,sizeof(dp));
    cout << go(n,m) << '\n';
      
    return 0;
}