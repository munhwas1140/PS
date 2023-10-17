#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[10001];
string str;
int n;
int check(int idx, int sz) {

    bool ok = true; 
    for(int i = idx; i < idx + sz; i++) {
        if(str[i] != str[idx]) ok = false;
    }
    if(ok) return 1;

    ok = true;
    for(int i = idx + 2; i < idx + sz; i++) {
        if(str[i] - str[i-1] != str[idx + 1] - str[idx]) ok = false;
    }
    if(ok) {
        if(abs(str[idx + 1] - str[idx]) == 1) return 2;
        return 5;
    }
    ok = true;
    for(int i = 0; i < sz; i++) {
        if(str[idx + i] != str[idx + i % 2]) ok = false;
    }
    if(ok) return 4;
    return 10;
}
int go(int idx) {
    if(idx == n) return 0;
    if(idx > n) return 1e9;

    int &ret = dp[idx];
    if(ret != -1) return ret;
    ret = 1e9;
    ret = min(ret, check(idx, 3) + go(idx + 3));
    ret = min(ret, check(idx, 4) + go(idx + 4));
    ret = min(ret, check(idx, 5) + go(idx + 5));
    return ret;
}
void solve() {
    cin >> str;
    n = str.size();
    memset(dp,-1,sizeof(dp));
    cout << go(0) << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}