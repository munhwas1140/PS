#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &[w, d] : a) {
        cin >> d >> w;
    }
    sort(a.rbegin(), a.rend());
    vector<bool> check(1001, false);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = a[i].second; j >= 1; j--) {
            if(!check[j]) {
                check[j] = true;
                ans += a[i].first;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}