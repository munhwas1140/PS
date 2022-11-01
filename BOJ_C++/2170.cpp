#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1e9 + 1;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    int ans = 0;
    int s, e;
    s = e = -INF;
    for(int i = 0; i < n; i++) {
        if(a[i].first > e) {
            ans += e - s;
            e = a[i].second;
            s = a[i].first;
        } else {
            e = max(a[i].second, e);
        }
    }
    ans += e - s;
    cout << ans << '\n';
    return 0;
}