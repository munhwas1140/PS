#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, s;
vector<pii> a;
vector<int> h;
int dp[300000];
int go(int now) {
    if(now >= n) return 0;
    int &ret = dp[now];
    if(ret != -1) return ret;

    int it = lower_bound(h.begin(), h.end(), a[now].first + s) - h.begin();

    ret = go(now + 1);

    ret = max(ret, a[now].second + go(it));
    return ret;
}
int main() {
    fastio;
    memset(dp,-1,sizeof(dp));
    cin >> n >> s;
    a.resize(n);
    h.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        h[i] = a[i].first;
    }
    sort(a.begin(), a.end());
    sort(h.begin(), h.end());
    cout << go(0) << '\n';


    return 0;
}