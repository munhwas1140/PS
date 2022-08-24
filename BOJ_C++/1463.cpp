#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int go(int now) {
    if(now == 1) return 0;
    
    int &ans = dp[now];
    if(ans != -1) return ans;

    ans = go(now - 1) + 1;
    if(now % 3 == 0) ans = min(ans, go(now / 3) + 1);
    if(now % 2 == 0) ans = min(ans, go(now / 2) + 1);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    cout << go(n) << '\n';
    return 0;
}