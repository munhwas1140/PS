#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MAX = 2e9 + 1;
int dp[502];
int a[502];
ll dpcnt[502];
int n, k;
int lis(int now) {
    int &ret = dp[now];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = now + 1; i <= n; i++) {
        if(now == - 1 || a[now] < a[i]) {
            ret = max(ret, lis(i) + 1);
        }
    }
    return ret;
}

ll count(int now) {
    if(lis(now) == 1) return 1;
    
    ll &ret = dpcnt[now];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int i = now + 1; i <= n; i++) {
        if(a[now] < a[i] && lis(now) == lis(i) + 1) {
            ret = min(MAX, ret + count(i));
        }
    }
    return ret;
}
void reconstruct(int now, int k, vector<int> &res) {
    if(now != 0) res.push_back(a[now]);

    vector<pii> followers;
    for(int next = now + 1; next <= n; next++) {
        if(a[now] < a[next] && lis(now) == lis(next) + 1) {
            followers.push_back({a[next], next});
        }
    }

    sort(followers.begin(), followers.end());

    for(int i = 0; i < followers.size(); i++) {
        int idx = followers[i].second;
        int cnt = count(idx);
        if(cnt <= k) {
            k -= cnt;
        } else {
            reconstruct(idx, k, res);
            break;
        }
    }
}
void solve() {
    memset(dp,-1,sizeof(dp));
    memset(dpcnt,-1,sizeof(dpcnt));
    memset(a,0,sizeof(a));
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = -1;
    k -= 1;
    vector<int> ans;
    reconstruct(0,k,ans);
    cout << lis(0) - 1 << '\n';
    for(int x : ans) {
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