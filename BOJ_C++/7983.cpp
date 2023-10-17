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
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [&](const pii &u, const pii &v) {
        if(u.second == v.second) return u.first < v.first;
        return u.second > v.second;
    });

    int now = 1e9 + 3;
    for(auto &[l, e] : a) {
        if(e < now) {
            now = e - l;
        } else {
            now -= l;
        }
    }
    cout << now << '\n';
    return 0;
}