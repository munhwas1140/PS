#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int dp[1000001];
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[a[i]] = dp[a[i] - 1] + 1;
    }
    cout << n - *max_element(dp, dp + 1000001) << '\n';
    return 0;
}