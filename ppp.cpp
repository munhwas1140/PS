#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9 + 7;
ll f[200001];
void solve() {
    ll n; cin >> n;
    vector<vector<ll>> g(n + 1);
    for(ll i = 0; i < n - 1; i++) {
        ll t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    vector<vector<ll>> gt(n + 1);
    vector<ll> d(n + 1);
    vector<ll> siz(n + 1);
    d[1] = 1;
    function<ll(ll, ll, ll)> dfs = [&] (ll now, ll p, ll dep) {
        siz[now] = 1;
        for(ll &next : g[now]) {
            if(next != p) {
                gt[now].push_back(next);
                d[next] = d[now] + 1;
                siz[now] += dfs(next, now, dep + 1);
            }
        }
        return siz[now];
    }
    dfs(1, -1, 1);

    ll ans = f[n - 1];
    cout << ans << '\n';
    vector<ll> dp(n + 1, -1);

    function<ll(ll)> go = [&] (ll now) {
        
        ll &ret = dp[now];
        if(ret != -1) return ret;
        ret = 0;

        for(ll &next : gt[now]) {
            ret += go(next);
            ret %= MOD;
        }
        

        ll sz = (ll)gt[now].size();
        if(sz != 0) {
            ll tmp = f[sz - 1] * f[n - d[now] - 1];
            tmp %= MOD;
            ret += tmp;
            ret %= MOD;
        }
        return ret;
    };

    ans *= go(1);
    cout << ans << '\n';
    
}
int main() {
    f[0] = 1LL;
    f[1] = 2LL;
    for(ll i = 2; i <= 200000; i++) {
        f[i] = f[i - 1] * 2;
        f[i] %= MOD;
    }
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}