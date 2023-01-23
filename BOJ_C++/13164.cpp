#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> diff;
    for(int i = 0; i < n - 1; i++) {
        diff.push_back(a[i + 1] - a[i]);
    }

    sort(diff.begin(), diff.end());
    ll ans = 0;
    for(int i = 0; i < diff.size() - k + 1; i++) {
        ans += (ll)diff[i];
    }
    cout << ans << '\n';

    return 0;
}