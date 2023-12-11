#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
string from, to;
int dp[10000][10];

int go(int idx, int left) {
    if(idx == n) return 0;
    int &ret = dp[idx][left];
    if(ret != -1) return ret;
    int now = ((from[idx] - '0') + left) % 10;
    int l = ((to[idx] - '0') - now + 10) % 10;
    int r = (now - (to[idx] - '0') + 10) % 10;
    ret = min(r + go(idx + 1, left), l + go(idx + 1, (left + l) % 10));
    return ret;
}
void tracking(int idx, int left) {
    if(idx == n) return ;
    int now = ((from[idx] - '0') + left) % 10;
    int l = ((to[idx] - '0') - now + 10) % 10;
    int r = (now - (to[idx] - '0') + 10) % 10;
    if(r + go(idx + 1,left) > l + go(idx + 1, (left + l) % 10)) {
        cout << idx + 1 << ' ' << l << '\n';
        tracking(idx + 1, (left + l) % 10);
    } else {
        cout << idx + 1 << ' ' << -r << '\n';
        tracking(idx + 1, left);
    }
}
int main() {
    fastio;
    cin >> n;
    cin >> from >> to;  
    memset(dp,-1,sizeof(dp));
    cout << go(0,0) << '\n';
    tracking(0,0);
    return 0;
}