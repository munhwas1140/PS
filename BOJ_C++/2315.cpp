#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int dp[1001][1001];
int go(int s, int e) {

}
int main() {
    fastio;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n + 1)
    vector<ll> psum(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        psum[i] = psum[i - 1] + a[i].first;
    }

    memset(dp,-1,sizeof(dp));
    cout << go(m, m) << '\n';

    return 0;
}