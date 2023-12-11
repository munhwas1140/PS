#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
bool check[100001];
int dp[10001][2];
int go(vector<pii> &a, int idx, int prev) {
    if(idx == n) return 0;
    dp[idx][0] = go(a, idx + 1, prev);
    if(prev < a[idx].second) {
        dp[idx][1] = a[idx].second + go(a, idx + 1, a[idx].second);
    }
    return max(dp[idx][0], dp[idx][1]);
}
void trace(int idx, int now = -1) {
    if(idx == n) return;
    cout << dp[idx][0] << ' ' << dp[idx][1] << '\n';
    if(dp[idx][1] >= dp[idx][0]) {
        check[idx] = true;
        trace(idx + 1, dp[idx][1]);
    } else {
        trace(idx + 1, dp[idx][0]);
    }
}
int main() {
    fastio;
    cin >> n;
    vector<pii> a(n);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        sum += a[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    
    sort(a.begin(), a.end());

    memset(dp,-1,sizeof(dp));
    sum += go(a, 0, -1);
    trace(0);
    for(int i = 0; i < n; i++) {
        cout << a[i].second << ' ' << check[i] << '\n';

        if(a[i].second > a[i].first && !check[i]) {
            sum += a[i].second - a[i].first;
        }
    }
    cout << sum << '\n';
    return 0;
}