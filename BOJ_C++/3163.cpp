#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, l, k;
void solve() {
    cin >> n >> l >> k;
    vector<pii> a(n);
    deque<int> ori(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].second > 0) a[i].first = l - a[i].first;
        ori[i] = a[i].second;
    }
    sort(a.begin(), a.end());

    vector<pii> ans(n);
    for(int i = 0; i < n; i++) {
        ans[i].first = a[i].first;
        if(a[i].second > 0) {
            ans[i].second = ori.back();
            ori.pop_back();
        } else {
            ans[i].second = ori.front();
            ori.pop_front();
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[k - 1].second << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}