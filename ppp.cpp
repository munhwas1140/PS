#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
string str;
int dp[10001];
int check(string tmp) {
    int n = tmp.size();
    char c = tmp[0];
    if(tmp == string(n, c)) return 1;
    bool ok = true;
    for(int i = 0; i < n - 1; i++) {
        if(tmp[i + 1] != tmp[i] + 1) ok = false;
    }
    if(ok) return 2;
    ok = true;
    for(int i = 0; i < n - 1; i++) {
        if(tmp[i + 1] != tmp[i] - 1) ok = false;
    }
    if(ok) return 2;

    ok = true;
    for(int i = 0; i < n - 2; i++) {
        if(tmp[i] != tmp[i + 2]) ok = false;
    }
    if(ok) return 4;
    
    ok = true;
    for(int i = 0; i < n - 1; i++) {
        if(tmp[i + 1] - tmp[i] != tmp[1] - tmp[0]) ok = false;
    }
    if(ok) return 5;
    return 10;
}
int go(int idx) {
    if(idx == str.size()) return 0;
    

    int &ret = dp[idx];
    if(ret != -1) return ret;

    ret = 1e9;
    if(idx + 3 <= str.size()) {
        ret = min(ret, go(idx + 3) + check(str.substr(idx, 3)));
    }
    if(idx + 4 <= str.size()) {
        ret = min(ret, go(idx + 4) + check(str.substr(idx, 4)));
    }
    if(idx + 5 <= str.size()) {
        ret = min(ret, go(idx + 5) + check(str.substr(idx, 5)));
    }
    return ret;
}
void solve() {
    cin >> str;
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