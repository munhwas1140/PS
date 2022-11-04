#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
string a[15];
ll dp[1 << 15][101];
int mod[15],tmp[51];
void precalc() {
    tmp[0] = 1;
    for(int i = 1; i <= 50; i++) {
        tmp[i] = (tmp[i - 1] * 10) % k;
    }
    for(int i = 0; i < n; i++) {
        ll tmp = 0;
        for(int j = 0; j < a[i].size(); j++) {
            tmp = (tmp * 10 + (a[i][j] - '0')) % k;
        }
        mod[i] = tmp;
    }
    return ;
}
ll go(int state, int nowmod) {
    if(state == ((1 << n) - 1)) {
        return nowmod == 0;
    }

    ll &ret = dp[state][nowmod];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        if(state & (1 << i)) continue;
        int nextstate = state | (1 << i);
        int nextMod = (nowmod * tmp[a[i].size()] % k + mod[i]) % k;
        ret += go(nextstate, nextMod);
    }
    
    return ret;
}
int main() {
    fastio;
    cin >> n;
    ll fac = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        fac *= i + 1;
    }
    cin >> k;
    precalc();
    memset(dp,-1,sizeof(dp));

    ll ans = go(0, 0);

    if(ans == 0) cout << "0/1" << '\n';
    else if(ans == fac) cout << "1/1" << '\n';
    else {
        ll gc = gcd(ans, fac);
        ans /= gc;
        fac /= gc;
        cout << ans << '/' << fac << '\n';
    }

    return 0;
}