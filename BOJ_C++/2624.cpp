#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
vector<pii> v;
int dp[10001][101];
int go(int now, int idx) {
    if(now < 0) return 0;
    if(now == 0) return 1;
    if(idx == m) return 0;
    
    int &ret = dp[now][idx];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i <= v[idx].second; i++) {
        ret += go(now - v[idx].first * i, idx + 1);
    }

    return ret;
}
int main() {
    fastio;
    cin >> n >> m;
    v.resize(m);
    for(int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    memset(dp, -1, sizeof(dp));
    cout << go(n, 0) << '\n';

    return 0;
}