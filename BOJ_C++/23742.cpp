#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<ll> a(n), p(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) idx = i;
        if(i == 0) p[i] = a[i];
        else p[i] = p[i - 1] + a[i];
    }
    ll ans = p[idx] * (idx + 1) + p[n - 1] - p[idx];
    for(int i = idx + 1; i < n; i++) {
        ans = max(ans, p[i] * (i + 1) + p[n - 1] - p[i]);
    }
    cout << ans << '\n';
    return 0;
}