#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MAX = 2e9 + 1;
int dp[502], a[502], n;
ll dpcnt[502];
ll k;
int lis(int now) {
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1;

    for(int next = now + 1; next <= n; next++) {
        if(a[now] < a[next]) {
            ret = max(ret, lis(next) + 1);
        }
    }
    return ret;
}
ll count(int now) {
    if(lis(now) == 1) return 1;

    ll &ret = dpcnt[now];
    if(ret != -1) return ret;
    ret = 0;
    for(int next = now + 1; next <= n; next++) {
        if(a[now] < a[next] && lis(now) == lis(next) + 1) {
            ret = min(MAX, ret + count(next));
        }
    }
    return ret;
}
void go(int now, int k, vector<int> &ans) {
    if(now != 0) ans.push_back(a[now]);

    vector<pii> cand;
    for(int next = now + 1; next <= n; next++) {
        if(a[now] < a[next] && lis(now) == lis(next) + 1) {
            cand.push_back({a[next], next});
        }
    }

    sort(cand.begin(), cand.end());
    
    for(int i = 0; i < cand.size(); i++) {
        int idx = cand[i].second;
        ll cnt = count(idx);
        if(k < cnt) {
            go(idx,k,ans);
            return ;
        } else {
            k -= cnt;
        }
    }

    return ;
}
void solve() {
    memset(dp,-1,sizeof(dp));
    memset(dpcnt,-1,sizeof(dpcnt));
    memset(a,0,sizeof(a));
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = -1;
    cout << lis(0) - 1 << '\n';
    vector<int> ans;
    go(0, k - 1, ans);
    for(int &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}