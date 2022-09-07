#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int dp[32][32];
string ans = "";
int go(int n, int m) {
    if(n == 0 || m == 0) return dp[n][m] = 1;

    int &ret = dp[n][m];
    if(ret != -1) return ret;

    ret = go(n-1, m);
    if(m > 0) ret += go(n-1,m-1);
    return ret;
}
void print(int n, int m, ll l) {
    if(n == 0) return ;
    if(dp[n-1][m] < l) {
        cout << 1;
        print(n-1,m-1,l - dp[n-1][m]);
    } else {
        cout << 0;
        print(n-1,m,l);
    }
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    int n, m;
    ll l;
    cin >> n >> m >> l;
    go(n, m);
    print(n,m,l);
    
    return 0;
}