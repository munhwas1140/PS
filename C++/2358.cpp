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
    for(auto &[x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end());
    map<int, int> mp;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int it = i;
        while(it < n && a[it].first == a[i].first) {
            mp[a[it++].second]++;
        }
        if(it != i + 1) {
            ans++;
            i = it - 1;
        }
    }

    for(auto &p : mp) if(p.second >= 2) ans++;
    cout << ans << '\n';
    return 0;
}