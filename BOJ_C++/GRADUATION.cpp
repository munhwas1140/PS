#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int prerequisite[12];
int classes[11];
int dp[1 << 12][10];
int n, k, m, l;
int go(int state, int seme) {
    int cnt = __builtin_popcount(state);
    if(cnt >= k) return 0;
    if(seme == m) return 1e9;

    int &ret = dp[state][seme];
    if(ret != -1) return ret;

    ret = 1e9;
    
    int canTake = (classes[seme] & ~state);

    for(int i = 0; i < n; i++) {
        if((canTake & (1 << i)) && ((state & prerequisite[i]) != prerequisite[i])) {
            canTake &= ~(1 << i);
        }
    }

    for(int take = canTake; take; (take = ((take - 1) & canTake))) {
        int tmp = __builtin_popcount(take);
        if(tmp > l) continue;
        ret = min(ret, go(state | take, seme + 1) + 1);
    }

    ret = min(ret, go(state, seme + 1));
    return ret;
}
void solve() {
    memset(prerequisite,0,sizeof(prerequisite));
    memset(classes,0,sizeof(classes));
    memset(dp,-1,sizeof(dp));

    cin >> n >> k >> m >> l;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            int tt; cin >> tt;
            prerequisite[i] |= (1 << tt);
        }
    }

    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            int tt; cin >> tt;
            classes[i] |= (1 << tt);
        }
    }

    int ans = go(0, 0);
    if(ans == 1e9) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << ans << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}