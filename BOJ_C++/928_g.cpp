#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 998244353;
int p[401];
ll dp[401];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[x] = y;
    }
}
ll f(int now) {
    if(now <= 1) return 1LL;

    ll &ret = dp[now];
    if(ret != -1) return ret;
    ret = (ll)now;
    ret *= f(now - 1);
    ret %= MOD;
    return ret;
}
int main() {
    fastio;

    memset(dp,-1,sizeof(dp));


    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> a;
    for(int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        a.push_back({t3, t1, t2});
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < m; i++) {
        memset(p,-1,sizeof(p));
        int cnt = 0;
        int idx = -1;
        ll tsum = 0;
        ll num = 0;
        ll tmp = 1;
        for(int j = i; j < m; j++) {
            if(cnt == n - 1) break;
            auto [cost, x, y] = a[j];
            x = find(x);
            y = find(y);
            if(x != y) {
                set_union(x, y);
                cnt++;
                tsum += cost;
                if(cost > idx) {
                    tmp *= f(num);
                    tmp %= MOD;
                    num = 1;
                    idx = cost;
                } else {
                    num++;
                }
            }
        }

        if(sum == 0) sum = tsum;

        if(cnt != n - 1 || sum != tsum) break;
        else {
            tmp *= f(num);
            ans += tmp;
        }
    }

    cout << ans << '\n'; 

    return 0;
}