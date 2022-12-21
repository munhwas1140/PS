#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> b;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            b.push_back(a[i] + a[j]);
        }
    }
    sort(b.begin(), b.end());

    // x + y = k - z;
    int ans = -1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int now = a[j] - a[i];
            auto it = lower_bound(b.begin(), b.end(), now);
            if(it != b.end() && *it == now) {
                ans = max(ans, a[j]);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}