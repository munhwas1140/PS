#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int pSum[100001];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        pSum[i] = pSum[i - 1] + val;
    }

    int ans = 0;
    int pSum2 = 0;
    for(int i = m; i <= n; i++) {
        pSum2 = min(pSum2, pSum[i - m]);
        ans = max(ans, pSum[i] - pSum2);
    }
    cout << ans << '\n';
    return 0;
}