#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
ll k;
ll dp[100001];
ll a[100001], psum[100001];
ll go(int now) {
    if(now == n) return 0LL;
    
    ll &ret = dp[now];
    if(ret != -1) return ret;

    ret = go(now + 1);

    int s = now, e = n - 1, mid;
    int idx = -1, ans = 0;
    while(s <= e) {
        mid = (s + e) / 2;
        ll tmp = psum[mid] - (now == 0 ? 0 : psum[now - 1]);
        if(tmp >= k) {
            ans = tmp - k;
            idx = mid;
            e = mid - 1;
        }  else {
            s = mid + 1;
        }
    }

    if(idx != -1) ret = max(ret, ans + go(idx + 1));
    return ret;
}
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0) psum[i] = a[i];
        else psum[i] = psum[i - 1] + a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << go(0) << '\n';
    return 0;
}