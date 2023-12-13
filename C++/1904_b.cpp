#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<pll> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin() + 1, a.end());

    vector<int> ans(n + 1);
    ll now = 0;
    int it = 1;
    for(int i = 1; i <= n; i++) {
        while(it <= n && (it <= i || now >= a[it].first)) {
            now += a[it].first;
            it++;
        }
        ans[i] = it - 2;
    }

    vector<int> rans(n + 1);
    for(int i = 1; i <= n; i++) {
        rans[a[i].second] = ans[i];
    }
    for(int i = 1; i <= n; i++) {
        cout << rans[i] << ' ';
    }
    cout << '\n';

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}