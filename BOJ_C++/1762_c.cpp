#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 998244353;
int n;
string str;
int psum[200001];
ll go(int idx, int sum) {
    if(idx > n) return 0;

    if(str[idx] == '0') {
        if(sum >= idx) return 0;
    } else {
        if(sum < idx) return 0;
    }
    
    ll ret = 1;
    ret += go(idx + 1, sum + (str[idx + 1] - '0'));
    ret %= MOD;
    ret += go(idx + 1, sum + (str[idx + 1] - '0') + 1);
    ret %= MOD;

    return ret;
}
void solve() {
    memset(psum, 0, sizeof(psum));
    cin >> n >> str;
    str = " " + str;

    ll ans = go(1, str[1] - '0');
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}