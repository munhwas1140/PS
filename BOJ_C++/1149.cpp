#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int dp[1000][4];
int a[1000][3];
int n;
int go(int now, int prev = 3) {
    if(now == n) return 0; 
    int &ret = dp[now][prev];
    if(ret != -1) return ret;
    ret = 1e9;
    
    for(int i = 0; i < 3; i++) {
        if(i == prev) continue;
        ret = min(ret,go(now + 1,i) + a[now][i]);
    }
    return ret ;
}
void tracking(int now, int prev = 3) {
    if(now == n) return;

    for(int i = 0; i < 3; i++) {
        if(prev != i && go(now + 1, i) + a[now][i] == go(now,prev)) {
            cout << "choice " << i << '\n';
            tracking(now + 1, i);
            return ;
        }
    }
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    } 
    cout << go(0) << '\n';
    // tracking(0);
    return 0;
}