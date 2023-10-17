#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int prereq[12];
int seme[10];
int dp[1 << 12][10];
int n, k, m, l;
int go(int state, int s) {
    int cnt = __builtin_popcount(state);
    if(cnt >= k) return 0;
    if(s == m) return 1e9;

    int &ret = dp[state][s];
    if(ret != -1) return ret;
    ret = 1e9;

    int pos = (seme[s] & ~state);

    for(int i = 0; i < n; i++) {
        if((pos & (1 << i)) && ((prereq[i] & state) != prereq[i])) {
            pos &= ~(1 << i);
        }
    }

    for(int take = pos; take; (take = ((take - 1) & pos))) {
        int tmp = __builtin_popcount(take);
        if(tmp > l) continue;
        ret = min(ret, go(state | take, s + 1) + 1);
    }
    ret = min(ret, go(state, s + 1));
    return ret;
}
void solve() {
    memset(prereq,0,sizeof(prereq));
    memset(seme,0,sizeof(seme));
    cin >> n >> k >> m >> l;

    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            int tt; cin >> tt;
            prereq[i] |= (1 << tt);
        }
    }

    for(int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        for(int j = 0; j < tmp; j++) {
            int tt; cin >> tt;
            seme[i] |= (1 << tt);
        }
    }

    memset(dp,-1,sizeof(dp));
    int ans = go(0,0);
    if(ans == 1e9) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << ans << '\n';
    }
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}