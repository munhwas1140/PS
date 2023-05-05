#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int main() {
    fastio;
    cin >> n;
    vector<pii> a(n);
    for(auto &[d, t] : a) {
        cin >> d >> t;
    }

    sort(a.rbegin(), a.rend());
    int ans = 0, it = 0;
    for(int i = a[it].first - 1; i >= 0; i--) {
        if(it == n) break;
        if(i % 7 >= 5 || i > a[it].first - 1) continue;

        a[it].second--;
        if(a[it].second == 0) it++;
    }

    if(it == n) return !(cout << 0 << '\n');

    for(int i = a[it].first - 1; i >= 0; i--) {
        if(it == n) break;
        if(i > a[it].first - 1) continue;

        a[it].second--; ans++;
        if(a[it].second == 0) it++;
    }

    if(it == n) cout << ans << '\n';
    else cout << -1 << '\n';

    return 0;
}