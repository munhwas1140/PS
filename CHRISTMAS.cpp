#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
int a[100001];
int psum[100001];
ll cnt[100001];
int go() {
    vector<int> ret(n + 1, 0);
    vector<int> prev(k, -1);
    for(int i = 0; i <= n; i++) {
        if(i > 0) {
            ret[i] = ret[i - 1];
        } else {
            ret[i] = 0;
        }
        int loc = prev[psum[i]];
        if(loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
        prev[psum[i]] = i;
    }
    return ret.back();
}
void solve() {
    memset(a,0,sizeof(a));
    memset(psum,0,sizeof(psum));
    memset(cnt,0,sizeof(cnt));
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    psum[0] = 0;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++) {
        psum[i] = (psum[i - 1] + a[i]) % k;
        cnt[psum[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        if(cnt[i] == 0) continue;
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
        ans %= 20091101LL;
    }
    cout << ans << ' ' << go() << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}