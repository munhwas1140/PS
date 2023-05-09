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
    for(auto &[d, x] : a) cin >> d >> x;

    sort(a.begin(), a.end());
    int it = 0;
    for(int i = 1; i <= a.back().first; i++) {
        while(it < n && (i > a[it].first || a[it].second == 0)) it++;
        if(it == n) break;
        if((i - 1) % 7 >= 5) continue;
        a[it].second--;
    }

    it = 0;
    int ans = 0;
    for(int i = 1; i <= a.back().first; i++) {
        while(it < n && (i > a[it].first || a[it].second == 0)) it++;
        if(it == n) break;
        a[it].second--;
        ans++;
    }

    for(int i = 0; i < n; i++) {
        if(a[i].second != 0) return !(cout << -1 << '\n');
    }
    cout << ans << '\n';


    return 0;
}