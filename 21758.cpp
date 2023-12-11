#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> psum(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    int ans = psum[n] - a[1] - a[n] + *max_element(a.begin() + 2, a.end() - 1);
    for(int i = 2; i < n; i++) {
        ans = max(ans, psum[n] - a[1] - a[i] + psum[n] - psum[i]);
        ans = max(ans, psum[n - 1] - a[i] + psum[i - 1]);
    }
    cout << ans << '\n';
    return 0;
}