// https://atcoder.jp/contests/abc221/tasks/abc221_d
#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<pii> a;
    vector<ll> ans(n + 1);
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a.push_back({t1, 1});
        a.push_back({t1 + t2, -1});
    }
    sort(a.begin(), a.end());



    int now = 0;
    int pre = 0;
    for(int i = 0; i < 2 * n; i++) {
        auto [x, d] = a[i];
        if(i) {
            ans[now] += (ll)(x - pre);
        }
        now += d;
        pre = x;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}