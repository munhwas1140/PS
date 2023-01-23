#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k, b;
    cin >> n >> k >> b;
    vector<bool> check(n + 1);

    for(int i = 0; i < b; i++) {
        int tmp; cin >> tmp;
        check[tmp] = true;
    }
    int cnt = 0;
    for(int i = 1; i <= k; i++) {
        cnt += check[i];
    }

    int ans = cnt;
    for(int i = k + 1; i <= n; i++) {
        cnt += check[i];
        cnt -= check[i - k];
        ans = min(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}